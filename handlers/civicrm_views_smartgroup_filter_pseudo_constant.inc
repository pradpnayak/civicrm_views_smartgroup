<?php

class civicrm_views_smartgroup_filter_pseudo_constant extends civicrm_handler_filter_pseudo_constant {
  function query() {
    civicrm_initialize();
    if ($this->operator == '=') {
      CRM_Contact_BAO_GroupContactCache::check($this->value['value']);
    }

    parent::query();
  }
}
