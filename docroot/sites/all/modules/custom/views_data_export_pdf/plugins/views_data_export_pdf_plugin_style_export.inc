<?php

/**
 * @file
 * PDF style plugin.
 */
class views_data_export_pdf_plugin_style_export extends views_data_export_plugin_style_export {

  /**
   * Set options fields and default values.
   *
   * @return
   * An array of options information.
   */
  function option_definition() {
    $options = parent::option_definition();

    $options['use_mpdf'] = [
      'default' => FALSE,
      'translatable' => FALSE,
    ];

    $options['disable_smart_shrinking'] = [
      'default' => FALSE,
      'translatable' => FALSE,
    ];

    $options['each_group_separate_table'] = [
      'default' => FALSE,
      'translatable' => FALSE,
    ];

    $options['landscape'] = [
      'default' => FALSE,
      'translatable' => FALSE,
    ];

    $options['page_width'] = [
      'default' => "",
      'translatable' => FALSE,
    ];

    $options['page_height'] = [
      'default' => "",
      'translatable' => FALSE,
    ];

    $options['user_style_sheet'] = [
      'default' => "",
      'translatable' => FALSE,
    ];
    return $options;
  }

  /**
   * Options form mini callback.
   *
   * @param $form
   * Form array to add additional fields to.
   * @param $form_state
   * State of the form.
   *
   * @return
   * None.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $mpdf_available = (module_exists("pdf_using_mpdf") && function_exists("pdf_using_mpdf_library_exist")) ? TRUE : FALSE;

    if ($mpdf_available) {
      $form['use_mpdf'] = [
        '#type' => 'checkbox',
        '#title' => t('Use "mpdf" instead of "wkhtmltopdf" for this view.'),
        '#default_value' => $this->options['use_mpdf'],
        '#description' => t('Switch to use mpdf library for rendering PDF.'),
      ];
    }

    $form['disable_smart_shrinking'] = [
      '#type' => 'checkbox',
      '#title' => t('Disable smart shrinking'),
      '#default_value' => $this->options['disable_smart_shrinking'],
      '#description' => t('Disable the intelligent shrinking strategy used by WebKit that makes the pixel/dpi ratio none constant.'),
    ];

    $form['each_group_separate_table'] = [
      '#type' => 'checkbox',
      '#title' => t('Each group as separate table'),
      '#default_value' => $this->options['each_group_separate_table'],
      '#description' => t('If used grouping, this option provide rendering each group as separate table.'),
    ];

    $form['landscape'] = [
      '#type' => 'checkbox',
      '#title' => t('Landscape'),
      '#default_value' => $this->options['landscape'],
      '#description' => t('PDF Landscape format.'),
    ];

    $form['page_width'] = [
      '#type' => 'textfield',
      '#title' => t('Page width'),
      '#default_value' => $this->options['page_width'],
      '#description' => t('Page width in mm. Left empty for default A4 format.'),
    ];
    $form['page_height'] = [
      '#type' => 'textfield',
      '#title' => t('Page height'),
      '#default_value' => $this->options['page_height'],
      '#description' => t('Page height in mm. Left empty for default A4 format.'),
    ];
    $form['user_style_sheet'] = [
      '#type' => 'textfield',
      '#title' => t('User style sheet path'),
      '#default_value' => $this->options['user_style_sheet'],
      '#description' => t('Add user style sheet from path. Example sites/default/files/pdf_style.css'),
    ];

  }

  function render_header() {
    $rows = [];
    $title = '';
    $output = '';
    $head = '';

    $is_style_sheet = (isset($this->options['user_style_sheet'])) ? $this->options['user_style_sheet'] : "";
    if (!empty($is_style_sheet)) {
      $path = ltrim($is_style_sheet, "/");
      if (!empty($path) && file_exists($path)) {
        $styles = [
          '#type' => 'styles',
          '#items' => [
            $path => [
              'type' => 'file',
              'group' => CSS_DEFAULT,
              'weight' => 0,
              'every_page' => FALSE,
              'media' => 'all',
              'preprocess' => FALSE,
              'data' => $path,
              'browsers' => [
                'IE' => TRUE,
                '!IE' => TRUE,
              ],
            ],
          ],
        ];
        $head = drupal_render($styles);
      }
      else {
        watchdog("views_data_export_pdf", "File not found :path", [":path" => $is_style_sheet]);
      }
    }

    $output .= theme($this->theme_functions($this->definition['additional themes base'] . '_header'), [
      'view' => $this->view,
      'options' => $this->options,
      'rows' => $rows,
      'title' => $title,
      'head' => $head,
    ]);
    return $output;
  }

  function render_body(&$batch_sandbox = NULL) {
    if ($this->uses_row_plugin() && empty($this->row_plugin)) {
      vpr('views_plugin_style_default: Missing row plugin');
      return;
    }

    // Group the rows according to the grouping field, if specified.
    $sets = $this->render_grouping($this->view->result, $this->options['grouping']);

    // Support 2 groups.
    $sets = $this->multigroup_support($sets);

    // Render each group separately and concatenate.  Plugins may override this
    // method if they wish some other way of handling grouping.
    $output = '';

    if (!isset($batch_sandbox['group_titles'])) {
      $batch_sandbox['group_titles'] = [];
    }

    $group_titles = (isset($batch_sandbox['group_titles'])) ? $batch_sandbox['group_titles'] : [];

    foreach ($sets as $title => $records) {
      if ($this->uses_row_plugin()) {
        $rows = [];
        foreach ($records as $row_index => $row) {
          $this->view->row_index = $row_index;
          $rows[] = $this->row_plugin->render($row);
        }
      }
      else {
        $rows = $records;
      }

      $output .= theme($this->theme_functions($this->definition['additional themes base'] . '_body'), [
        'view' => $this->view,
        'options' => $this->options,
        'rows' => $rows,
        'title' => $title,
        'group_titles' => $group_titles,
      ]);

      if (!in_array($title, $batch_sandbox['group_titles'])) {
        $batch_sandbox['group_titles'][] = $title;
      }

    }
    unset($this->view->row_index);
    return $output;
  }
}
