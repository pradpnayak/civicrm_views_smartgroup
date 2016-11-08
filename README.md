# CiviCRM Views Smartgroup

This is a Drupal module that attempts to expose CiviCRM group contacts to Drupal Views for both regular and smartgroups.

Currently, CiviCRM exposes group contacts to Drupal Views for regular CiviCRM groups. However, smartgroup contacts are built 'on the fly' and are saved in a cache table that is separate from the `civicrm_group_contact` table.

This module uses a third table that merges contact from both the regular group contact table and the smartgroup cache table.

## Caveats and known issues

* The initial implementation of this module was to use to use a mysql view to dynamically merge both the regular and smartgroup cache tables. However, mysql does not have the option for materialized views and so with large numbers of contacts, querying this table became prohibitively expensive. Instead, we have had to use a regular mysql table for which it's our responsibility to keep up to date. Which leads us to...
* We use triggers on the `civicrm_group_contact` and `civicrm_group_contact_cache` tables to keep the merge table up to date. However, except in the very latest versions of mysql, only one trigger is allowed to be attached to a table at a time — which means we need to replace the CiviCRM logging triggers if logging is enabled. Therefore, logging will be disabled for group contacts.
* If logging is enabled, CiviCRM will attempt to wipe our triggers periodically and replace with its own. This means the merged table can become stale unless the Drupal cron is regularly run...
* The Drupal cron needs to be regularly run. This cron will 1) rebuild the `civicrm_group_contact_cache` table from the smartgroups definitions for all groups 2) repopulate the merge table with contact data and 3) reattach triggers to the `civicrm_group_contact` and `civicrm_group_contact_cache` tables (which may no longer exist thanks to CiviCRM logging).
* In general, the `civicrm_group_contact_cache` table won't be rebuilt except when the Drupal cron is run. This means there is the potential for group contacts to appear empty or to be stale. However, using a group ID in the Views argument or filter, or the group name in the Views filter, will cause the cache to updated for that specific smartgroup.