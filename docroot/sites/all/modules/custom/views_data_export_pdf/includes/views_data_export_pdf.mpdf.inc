<?php

/**
 * @file
 * Views data export mpdf functions.
 */

/**
 * Check if mpdf exist and available.
 */
function views_data_export_pdf_mpdf_exist() {
  $mpdf_available = (module_exists("pdf_using_mpdf") && function_exists("pdf_using_mpdf_library_exist")) ? TRUE : FALSE;
  return ($mpdf_available) ? pdf_using_mpdf_library_exist() : FALSE;
}

/**
 * Generate PDF.
 */
function views_data_export_pdf_mpdf_generator($html, $options = [], $filename = NULL) {

  // International Paper Sizes ( width x height).
  $paper_size = [
    '4A0' => ['w' => 1682, 'h' => 2378],
    '2A0' => ['w' => 1189, 'h' => 1682],
    'A0' => ['w' => 841, 'h' => 1189],
    'A1' => ['w' => 594, 'h' => 841],
    'A2' => ['w' => 420, 'h' => 594],
    'A3' => ['w' => 297, 'h' => 420],
    'A4' => ['w' => 210, 'h' => 297],
    'A5' => ['w' => 148, 'h' => 210],
    'A6' => ['w' => 105, 'h' => 148],
    'A7' => ['w' => 74, 'h' => 105],
    'A8' => ['w' => 52, 'h' => 74],
    'A9' => ['w' => 37, 'h' => 52],
    'A10' => ['w' => 26, 'h' => 37],

    'B0' => ['w' => 1000, 'h' => 1414],
    'B1' => ['w' => 707, 'h' => 1000],
    'B2' => ['w' => 500, 'h' => 707],
    'B3' => ['w' => 353, 'h' => 500],
    'B4' => ['w' => 250, 'h' => 353],
    'B5' => ['w' => 176, 'h' => 250],
    'B6' => ['w' => 125, 'h' => 176],
    'B7' => ['w' => 88, 'h' => 125],
    'B8' => ['w' => 62, 'h' => 88],
    'B9' => ['w' => 44, 'h' => 62],
    'B10' => ['w' => 31, 'h' => 44],

    'C0' => ['w' => 917, 'h' => 1297],
    'C1' => ['w' => 648, 'h' => 917],
    'C2' => ['w' => 458, 'h' => 648],
    'C3' => ['w' => 324, 'h' => 458],
    'C4' => ['w' => 229, 'h' => 324],
    'C5' => ['w' => 162, 'h' => 229],
    'C6' => ['w' => 114, 'h' => 162],
    'C7' => ['w' => 81, 'h' => 114],
    'C8' => ['w' => 57, 'h' => 81],
    'C9' => ['w' => 40, 'h' => 57],
    'C10' => ['w' => 28, 'h' => 40],

    'RA0' => ['w' => 860, 'h' => 1220],
    'RA1' => ['w' => 610, 'h' => 860],
    'RA2' => ['w' => 430, 'h' => 610],
    'SRA0' => ['w' => 900, 'h' => 1280],
    'SRA1' => ['w' => 640, 'h' => 900],
    'SRA2' => ['w' => 450, 'h' => 640],

    'Letter' => ['w' => 215.9, 'h' => 279.4],
    'Legal' => ['w' => 215.9, 'h' => 355.6],
    'Ledger' => ['w' => 279.4, 'h' => 431.8],
  ];

  $root_path = drupal_get_path('module', 'pdf_using_mpdf');
  $module_path = drupal_get_path('module', 'pdf_using_mpdf');
  global $theme_path;

  if (isset($options['page-width']) && isset($options['page-height'])) {
    if(isset($options['orientation']) && $options['orientation'] == "landscape") {
      $page_size = [$options['page-height'], $options['page-width']];
    } else {
      $page_size = [$options['page-width'], $options['page-height']];
    }

  }
  else {
    $page = variable_get('pdf_using_mpdf_pdf_page_size');
    if(isset($options['orientation']) && $options['orientation'] == "landscape") {
      $page_size = [$paper_size[$page]['h'], $paper_size[$page]['w']];
    } else {
      $page_size = [$paper_size[$page]['w'], $paper_size[$page]['h']];
    }
  }

  if (isset($options['font-size'])) {
    $font_size = $options['font-size'];
  }
  else {
    $font_size = variable_get('pdf_using_mpdf_pdf_font_size');
  }

  $font_style = variable_get('pdf_using_mpdf_pdf_default_font');

  // DEFAULT PDF margin Values.
  $margin_top = variable_get('pdf_using_mpdf_margin_top', 16);
  $margin_right = variable_get('pdf_using_mpdf_margin_right', 15);
  $margin_bottom = variable_get('pdf_using_mpdf_margin_bottom', 16);
  $margin_left = variable_get('pdf_using_mpdf_margin_left', 15);
  $margin_header = variable_get('pdf_using_mpdf_margin_header', 9);
  $margin_footer = variable_get('pdf_using_mpdf_margin_footer', 9);

  // Creating Instance of mPDF Class Library.
  $mpdf = new mPDF(
    '',
    $page_size,
    $font_size,
    $font_style,
    $margin_left,
    $margin_right,
    $margin_top,
    $margin_bottom,
    $margin_header,
    $margin_footer
  );

  // set document DPI
  $mpdf->dpi = (int) variable_get('pdf_using_mpdf_dpi', 96);

  // Set image DPI
  $mpdf->img_dpi = (int) variable_get('pdf_using_mpdf_img_dpi', 96);

  // Enabling header option if available.
  $header = (isset($options['header-html']) && !empty($options['header-html'])) ? $options['header-html'] : variable_get('pdf_using_mpdf_pdf_header');
  if (isset($header) && $header != NULL) {
    $header = token_replace($header);
    $mpdf->SetHTMLHeader($header);
  }

  // Enabling Footer option if available.
  $footer = (isset($options['footer-html']) && !empty($options['footer-html'])) ? $options['footer-html'] : variable_get('pdf_using_mpdf_pdf_footer');
  if (isset($footer) && $footer != NULL) {
    $footer = token_replace($footer);
    $mpdf->SetHTMLFooter($footer);
  }

  // Setting Watermark Text to PDF.
  $watermark_option = variable_get('pdf_using_mpdf_watermark_option');
  $watermark_opacity = variable_get('pdf_using_mpdf_watermark_opacity');

  // For watermark Text.
  if ($watermark_option == 'text') {
    $text = variable_get('pdf_using_mpdf_pdf_watermark_text');
    if (isset($text) && $text != NULL) {
      $mpdf->SetWatermarkText($text, $watermark_opacity);
      $mpdf->showWatermarkText = TRUE;
    }
  }
  // For watermark Image.
  else {
    $image_id = variable_get('pdf_using_mpdf_watermark_image');
    if (isset($image_id) && $image_id != NULL) {
      // Load the file via file.fid.
      $file = file_load($image_id);
      if (is_object($file)) {
        $file->status = FILE_STATUS_PERMANENT;
        file_save($file);
        file_usage_add($file, 'pdf_using_mpdf', 'image', $image_id);

        $image_path = file_create_url($file->uri);
        $mpdf->SetWatermarkImage($image_path, $watermark_opacity, '', 'P');
        $mpdf->showWatermarkImage = TRUE;
      }
    }
  }

  // Setting Title to PDF.
  $title = variable_get('pdf_using_mpdf_pdf_set_title');
  if (isset($title) && $title != NULL) {
    $mpdf->SetTitle($title);
  }

  // Setting Author to PDF.
  $author = variable_get('pdf_using_mpdf_pdf_set_author');
  if (isset($author) && $author != NULL) {
    $mpdf->SetAuthor($author);
  }

  // Setting Subject to PDF.
  $subject = variable_get('pdf_using_mpdf_pdf_set_subject');
  if (isset($subject) && $subject != NULL) {
    $mpdf->SetSubject($subject);
  }

  // Setting creator to PDF.
  $creator = variable_get('pdf_using_mpdf_pdf_set_creator');
  if (isset($creator) && $creator != NULL) {
    $mpdf->SetCreator($creator);
  }

  // Setting Password to PDF.
  $password = variable_get('pdf_using_mpdf_pdf_password');
  if (isset($password) && $password != NULL) {
    // Print and Copy is allowed.
    $mpdf->SetProtection(['print', 'copy'], $password, $password);
  }

  // Setting CSS stylesheet to PDF.
  $stylesheet = variable_get('pdf_using_mpdf_pdf_css_file');
  $stylesheet_content = NULL;
  if (isset($stylesheet) && $stylesheet != NULL) {
    $css_file_module = file_scan_directory($module_path, '/.*\.css$/');
    $css_file_theme = file_scan_directory($theme_path, '/.*\.css$/');
    // Check module directory
    if (isset($css_file_module[$module_path . '/' . $stylesheet])) {
      $stylesheet_content = file_get_contents($module_path . '/' . $stylesheet);
      $mpdf->WriteHTML($stylesheet_content, 1);
    }
    // Check theme directory
    elseif (isset($css_file_theme[$theme_path . '/' . $stylesheet])) {
      $stylesheet_content = file_get_contents($theme_path . '/' . $stylesheet);
      $mpdf->WriteHTML($stylesheet_content, 1);
    }
    else {
      drupal_set_message(t('CSS style Sheet mentioned in PDF setting was not found.'), 'warning');
      return TRUE;
    }
  }

  if (isset($options['user_style_sheet']) && !empty($options['user_style_sheet'])) {
    $mpdf->WriteHTML($options['user_style_sheet'], 1);
  }

  // Writing html content for pdf buffer.
  $mpdf->WriteHTML($html);

  // Generating PDF File.
  switch (variable_get('pdf_using_mpdf_pdf_save_option')) {
    case 1:
      // Dialog box for Download as PDF.
      $mpdf->Output($filename . '.pdf', 'D');
      exit;
      break;
    case 2:
      $folder = pdf_using_mpdf_get_folder();
      if (is_dir(drupal_realpath($folder))) {
        if (!pdf_using_mpdf_is_writable(drupal_realpath($folder))) {
          die('not writtable');
          if (drupal_rmdir($folder)) {
            drupal_mkdir($folder);
            drupal_chmod($folder, 0777);
          }
          else {
            drupal_set_message(t("Please ensure that public folder is writable."));
            exit;
          }
        }
      }
      else {
        if (pdf_using_mpdf_is_writable(drupal_realpath(file_build_uri('public://')))) {
          drupal_mkdir($folder);
          drupal_chmod($folder, 0777);
        }
        else {
          drupal_set_message(t("Please ensure that public folder is writable."));
          exit;
        }
      }
      // Save to server 'Public file system path'.
      $path = $folder . '/' . $filename . '.pdf';
      $mpdf->Output($path, 'F');
      drupal_goto($_SERVER['HTTP_REFERER']);
      exit;
      break;
    case 0:
    default:
      // Open in same browser.
      $mpdf->Output($filename . '.pdf', 'I');
      exit;
      break;
  }

  return TRUE;
}