<?php

/**
 * @file
 * Contains the bulk export display plugin.
 *
 * This allows views to be rendered in parts by batch API.
 */

/**
 * The plugin that batches its rendering.
 *
 * We are based on a feed display for compatibility.
 *
 * @ingroup views_display_plugins
 */
class views_data_export_pdf_plugin_display_export extends views_data_export_plugin_display_export {

  /**
   * Generate pdf file.
   */
  public function generate_pdf($html, $filename = NULL) {
    $use_mpdf = (isset($this->options['style_options']['use_mpdf']) && $this->options['style_options']['use_mpdf']) ? TRUE : FALSE;
    $options = [];
    $is_landscape = (isset($this->options['style_options']['landscape']) && $this->options['style_options']['landscape']) ? TRUE : FALSE;
    if ($is_landscape) {
      $options['orientation'] = 'landscape';
    }

    $page_width = (isset($this->options['style_options']['page_width'])) ? $this->options['style_options']['page_width'] : "";
    $page_height = (isset($this->options['style_options']['page_height'])) ? $this->options['style_options']['page_height'] : "";

    if (!empty($page_width) && !empty($page_height)) {
      $options['page-width'] = $page_width;
      $options['page-height'] = $page_height;
    }

    if ($use_mpdf) {
      module_load_include("inc", "views_data_export_pdf", "includes/views_data_export_pdf.mpdf");
      if (!views_data_export_pdf_mpdf_exist()) {
        drupal_set_message(t("mpdf does not installed properly"), "error");
        return $html;
      }

      $options['font-size'] = 12;

      $options['header-html'] = theme("views_data_export_pdf_pheader", ['view' => $this->view]);;
      $options['footer-html'] = theme("views_data_export_pdf_pfooter", ['view' => $this->view]);;

      $is_style_sheet = (isset($this->options['style_options']['user_style_sheet'])) ? $this->options['style_options']['user_style_sheet'] : "";
      if (!empty($is_style_sheet)) {
        $path = ltrim($is_style_sheet, "/");
        if (!empty($path) && file_exists($path)) {
          $options['user_style_sheet'] = file_get_contents($path);
        }
      }

      if (empty($filename)) {
        $filename = $this->view->name;
      }
      drupal_alter("views_data_export_wkhtmltopdf_options", $options);

      views_data_export_pdf_mpdf_generator($html, $options, $filename);
    } else {
      if (($library = libraries_load('phpwkhtmltopdf')) && !empty($library['loaded'])) {
        try {
          $options['binary'] = variable_get('views_data_export_pdf_wkhtmltopdf', '/usr/local/bin/wkhtmltopdf');

          $disable_smart_shrinking = (isset($this->options['style_options']['disable_smart_shrinking']) && $this->options['style_options']['disable_smart_shrinking']) ? TRUE : FALSE;
          if ($disable_smart_shrinking) {
            $options[] = 'disable-smart-shrinking';
          }

          $options['header-html'] = url("views_data_export_pdf/header-html/" . $this->view->name, array("absolute" => TRUE));
          $options['footer-html'] = url("views_data_export_pdf/footer-html/" . $this->view->name, array("absolute" => TRUE));

          drupal_alter("views_data_export_wkhtmltopdf_options", $options);

          $pdf = new WkHtmlToPdf($options);

          $pdf->addPage($html);
          if (!empty($filename)) {
            if ($pdf->saveAs($filename)) {
              return TRUE;
            }
            else {
              watchdog("views_data_export_pdf", $pdf->getError());
              return FALSE;
            }
          }
          else {
            ob_start();
            if ($pdf->send('php://output')) {
              $this->add_http_headers();
              return ob_get_clean();
            }
            else {
              watchdog("views_data_export_pdf", $pdf->getError());
              return $pdf->getError();
            }
          }

        }
        catch (Exception $exception) {
          watchdog("views_data_export_pdf", $exception->getMessage());
          return $exception->getMessage();
        }
      }
      else {
        watchdog("views_data_export_pdf", $library['error message']);
        return $library['error message'];
      }
    }

    return $html;
  }

  function parseTable($html)
  {
    // Find the table
    preg_match("/<table.*?>.*?<\/[\s]*table>/s", $html, $table_html);

    // Get title for each row
    preg_match_all("/<th.*?>(.*?)<\/[\s]*th>/", $table_html[0], $matches);
    $row_headers = $matches[1];

    // Iterate each row
    preg_match_all("/<tr.*?>(.*?)<\/[\s]*tr>/s", $table_html[0], $matches);

    $table = array();

    foreach($matches[1] as $row_html)
    {
      preg_match_all("/<td.*?>(.*?)<\/[\s]*td>/", $row_html, $td_matches);
      $row = array();
      for($i=0; $i<count($td_matches[1]); $i++)
      {
        $td = strip_tags(html_entity_decode($td_matches[1][$i]));
        $row[$row_headers[$i]] = $td;
      }

      if(count($row) > 0)
        $table[] = $row;
    }
    return $table;
  }

  /**
   * Render the display.
   *
   * We basically just work out if we should be rendering the header, body or
   * footer and call the appropriate functions on the style plugins.
   */
  function render() {
    if (!$this->is_batched()) {
      $result = $this->view->style_plugin->render($this->view->result);

      if (empty($this->view->live_preview) && isset($this->options['style_options']['provide_file']) && $this->options['style_options']['provide_file']) {
        $result = $this->generate_pdf($result);
      }

      return $result;
    }

    $this->view->build();

    switch ($this->batched_execution_state->batch_state) {
      case VIEWS_DATA_EXPORT_BODY:
        $output = $this->view->style_plugin->render_body($this->batched_execution_state->sandbox);
        break;
      case VIEWS_DATA_EXPORT_HEADER:
        $output = $this->view->style_plugin->render_header();
        break;
      case VIEWS_DATA_EXPORT_FOOTER:
        $output = $this->view->style_plugin->render_footer();
        break;
    }

    return $output;
  }

  /**
   * Transfer the output file to the client.
   */
  function transfer_file() {
    // Generate PDF instead of html file.
    if (empty($this->view->live_preview) && isset($this->options['style_options']['provide_file']) && $this->options['style_options']['provide_file']) {
      $output_file = $this->outputfile_path();
      $html = file_get_contents($output_file);
      if (!empty($html)) {
        $pdf_result = $this->generate_pdf($html, $output_file);
        if ($pdf_result && $file = $this->outputfile_entity()) {
          $file->filesize = filesize($file->uri);
          $file->filemime = file_get_mimetype($file->uri);
          file_save($file);
          $this->_output_file = $file;
        }
      }
    }

    // Build the view so we can set the headers.
    $this->view->build();
    // Arguments can cause the style to not get built.
    if (!$this->view->init_style()) {
      $this->view->build_info['fail'] = TRUE;
    }
    // Set the headers.
    if (empty($this->view->live_preview) && isset($this->options['style_options']['provide_file']) && $this->options['style_options']['provide_file']) {
      $this->add_http_headers();
    }
    $headers = [
      'Content-Length' => $this->outputfile_entity()->filesize,
    ];

    file_transfer($this->outputfile_path(), $headers);
  }


  /**
   * Define the option for this view.
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['use_batch'] = ['default' => 'no_batch'];
    $options['items_per_page'] = ['default' => '0'];
    $options['return_path'] = ['default' => ''];
    $options['style_plugin']['default'] = 'views_data_export_pdf';

    // This is the default size of a segment when doing a batched export.
    $options['segment_size']['default'] = 100;

    if (isset($options['defaults']['default']['items_per_page'])) {
      $options['defaults']['default']['items_per_page'] = FALSE;
    }

    return $options;
  }

  function get_style_type() {
    return 'data_export_pdf';
  }

}
