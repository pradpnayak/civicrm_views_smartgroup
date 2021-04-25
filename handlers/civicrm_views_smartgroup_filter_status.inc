<?php

class civicrm_views_smartgroup_filter_status extends views_handler_filter_in_operator {

  static $groupContactStatus = NULL;
  function construct() {
    parent::construct();
  }

  function get_value_options() {
    if (!isset($this->value_options)) {
      $this->value_title = t('Contact Group Status');
      $this->value_options = [];
      foreach (['Added', 'Removed', 'Pending', 'Smartgroup'] as $id => $name) {
        $this->value_options[$name] = $name;
      }
    }
  }
}
