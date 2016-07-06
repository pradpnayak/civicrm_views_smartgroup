<?php

class civicrm_views_smartgroup_filter_numeric extends views_handler_filter_numeric {
  function query() {
    civicrm_initialize();
    if ($this->operator == '=') {
      CRM_Contact_BAO_GroupContactCache::check($this->value['value']);
    }

    parent::query();
  }
}
