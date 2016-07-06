<?php

class civicrm_views_smartgroup_argument_numeric extends views_handler_argument_numeric {
  function query() {
    civicrm_initialize();
    if ($this->argument) {
      CRM_Contact_BAO_GroupContactCache::check($this->argument);
    }

    parent::query();
  }
}
