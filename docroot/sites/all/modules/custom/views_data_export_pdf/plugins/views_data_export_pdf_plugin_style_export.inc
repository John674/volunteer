<?php

/**
 * @file
 * PDF style plugin.
 */
class views_data_export_pdf_plugin_style_export extends views_data_export_plugin_style_export {
  /**
   * Render the display in this style.
   */
  function render() {
    return parent::render();
  }

  function render_body(&$batch_sandbox = NULL) {
    if ($this->uses_row_plugin() && empty($this->row_plugin)) {
      vpr('views_plugin_style_default: Missing row plugin');
      return;
    }

    // Group the rows according to the grouping field, if specified.
    $sets = $this->render_grouping($this->view->result, $this->options['grouping']);

    // Render each group separately and concatenate.  Plugins may override this
    // method if they wish some other way of handling grouping.
    $output = '';

    if (!isset($batch_sandbox['group_titles'])) {
      $batch_sandbox['group_titles'] = array();
    }

    $group_titles = (isset($batch_sandbox['group_titles'])) ? $batch_sandbox['group_titles'] : array();

    foreach ($sets as $title => $records) {
      if ($this->uses_row_plugin()) {
        $rows = array();
        foreach ($records as $row_index => $row) {
          $this->view->row_index = $row_index;
          $rows[] = $this->row_plugin->render($row);
        }
      }
      else {
        $rows = $records;
      }

      $output .= theme($this->theme_functions($this->definition['additional themes base'] . '_body'), array(
        'view' => $this->view,
        'options' => $this->options,
        'rows' => $rows,
        'title' => $title,
        'group_titles' => $group_titles
      ));

      if (!in_array($title, $batch_sandbox['group_titles'])) {
        $batch_sandbox['group_titles'][] = $title;
      }

    }
    unset($this->view->row_index);
    return $output;

  }
}
