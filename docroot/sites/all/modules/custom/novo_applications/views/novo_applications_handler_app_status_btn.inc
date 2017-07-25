<?php

/**
 * @file
 * Definition of novo_applications_handler_app_status_btn.
 */

/**
 * Render a novo_applications_handler_app_status_btn as a field.
 */
class novo_applications_handler_app_status_btn extends views_handler_field {

  /**
   * Override init function to add uid and homepage fields.
   */
  public function init(&$view, &$data) {
    parent::init($view, $data);
    $this->additional_fields['uid'] = 'uid';
  }

  /**
   * Renders the field handler.
   */
  public function render($values) {
    $uid = $this->get_value($values, "uid");

    $app_node_exist_nid = $this->checkAppNodeExist($uid);

    if ($app_node_exist_nid) {
      $query = drupal_get_destination();
      $output = l('<i class="glyphicon glyphicon-ok"></i>', "node/" . $app_node_exist_nid, array(
        'query' => $query,
        'html' => TRUE
      ));

    }
    else {
      $query = drupal_get_destination();
      $query = array_merge($query, array("uid" => $uid));
      $output = l('<i class="glyphicon glyphicon-plus"></i>', 'node/add/application', array(
        'query' => $query,
        'html' => TRUE,
        'attributes' => array('class' => array("btn", "btn-danger", "btn-xs"))
      ));
    }

    return $output;
  }

  private function checkAppNodeExist($uid) {
    $app_node_obj = novo_applications_get_user_app($uid);
    return (isset($app_node_obj->nid) && !empty($app_node_obj->nid)) ? $app_node_obj->nid : FALSE;
  }

}
