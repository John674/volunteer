<?php

/**
 * @file
 * Definition of novo_applications_handler_app_status_btn.
 */

/**
 * Render a novo_applications_handler_app_status_btn as a field.
 */
class novo_applications_handler_app_status_btn extends views_handler_field {

  private $volunter_role = "Applicant US citizen";

  /**
   * Override init function to add uid and homepage fields.
   */
  public function init(&$view, &$data) {
    parent::init($view, $data);
    $this->additional_fields['uid'] = 'uid';
  }

  /**
   * Check volunteer role.
   */
  public function pre_render(&$values) {
    $uids = array();
    $this->items = array();

    $roles = user_roles();
    $vol_rid = array_keys($roles, $this->volunter_role);
    $vol_rid = reset($vol_rid);

    foreach ($values as $result) {
      $uids[] = $result->uid;
    }

    if ($uids) {
      $query = db_select("users_roles", "ur");
      $query->fields("ur", array("uid", "rid"));
      $query->addField("ur", "rid", "rid");
      $query->condition("ur.uid", $uids, "IN");
      $result = $query->execute()->fetchAllKeyed();

      foreach ($values as $key => $value) {
        if (array_key_exists($value->uid, $result) && $result[$value->uid] == $vol_rid) {
          $values[$key]->volunteer = TRUE;
        }
      }
    }
  }

  /**
   * Renders the field handler.
   */
  public function render($values) {
    $uid = $this->get_value($values, "uid");
    $volunteer = isset($values->volunteer) ? $values->volunteer : FALSE;

    if ($volunteer) {
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
          'attributes' => array('class' => array())
        ));
      }
    }
    else {
      $output = "";
    }


    return $output;
  }

  /**
   * Check if exist application for user.
   */
  private function checkAppNodeExist($uid) {
    $app_node_obj = novo_applications_get_user_app($uid);
    return (isset($app_node_obj->nid) && !empty($app_node_obj->nid)) ? $app_node_obj->nid : FALSE;
  }

}
