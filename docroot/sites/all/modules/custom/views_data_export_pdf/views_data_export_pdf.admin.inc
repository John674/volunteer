<?php

/**
 * @file
 * Views_data_export_pdf admin form.
 */

/**
 * Implements form callback.
 */
function views_data_export_pdf_settings_form() {
  $form = [];
  $form['views_data_export_pdf_wkhtmltopdf'] = [
    '#type' => 'textfield',
    '#title' => t('WkhtmlToPdf Location'),
    '#description' => t('Set this to the system path where WkhtmlToPdf is located.'),
    '#default_value' => variable_get('views_data_export_pdf_wkhtmltopdf', '/usr/local/bin/wkhtmltopdf'),
  ];

  $mpdf_available = (module_exists("pdf_using_mpdf") && function_exists("pdf_using_mpdf_library_exist")) ? TRUE : FALSE;

  if (!$mpdf_available) {
    $text = t('For using mpdf install !link module and "mpdf" library.', ["!link" => l("PDF using mPDF", "https://www.drupal.org/project/pdf_using_mpdf")]);
  }
  else {
    $text = t('For using mpdf choose mpdf option in the specific view');
  }

  $form['views_data_export_pdf_mpdf_text'] = [
    '#type' => 'markup',
    '#markup' => $text,
  ];

  return system_settings_form($form);
}
