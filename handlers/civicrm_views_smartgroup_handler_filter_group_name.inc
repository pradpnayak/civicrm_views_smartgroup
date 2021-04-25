<?php
/*
 +--------------------------------------------------------------------+
 | Copyright CiviCRM LLC. All rights reserved.                        |
 |                                                                    |
 | This work is published under the GNU AGPLv3 license with some      |
 | permitted exceptions and without any warranty. For full license    |
 | and copyright information, see https://civicrm.org/licensing       |
 +--------------------------------------------------------------------+
 */


/**
 * CiviCRM Views Integration
 */
class civicrm_views_smartgroup_handler_filter_group_name extends views_handler_filter_in_operator {
  private $civi_groups;

  public function construct() {
    parent::construct();

    if (empty($this->civi_groups)) {
      if (!civicrm_initialize()) {
        return;
      }
      $result = civicrm_api3('Group', 'get', [
        'return' => ['name', 'title'],
        'is_hidden' => 0,
        'is_active' => 1,
        'options' => ['limit' => 0, 'sort' => 'title'],
      ])['values'];
      $this->civi_groups = array_column($result, 'title', 'name');
    }
  }

  public function get_value_options() {
    if (!isset($this->value_options)) {
      $this->value_title = t('Contact Group Title');
      $this->value_options = $this->civi_groups;
    }
  }

}
