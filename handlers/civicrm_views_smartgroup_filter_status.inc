<?php

class civicrm_views_smartgroup_filter_status extends views_handler_filter_in_operator {

  static $groupContactStatus = NULL;
  function construct() {
    parent::construct();

    if (!self::$groupContactStatus) {
      if (!civicrm_initialize()) {
        return;
      }
      self::$groupContactStatus = array(
        0 => 'Added',
        1 => 'Removed',
        2 => 'Pending',
        3 => 'Smartgroup',
      );
    }
  }

  function get_value_options() {
    if (!isset($this->value_options)) {
      $this->value_title = t('Contact Group Status');
      $options = array();
      foreach (self::$groupContactStatus as $id => $name) {
        $options[$name] = $name;
      }
      $this->value_options = $options;
    }
  }
}