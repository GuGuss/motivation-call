<?php
/*
 * Implement hook_migrate_api()
 */
function motivation_call_migrate_migrate_api() {
  $api = array(
    'api' => 2,
    'groups' => array(
      'motivation_call' => array(
        'title' => t('Motivation Call Migration'),
      ),
    ),
    'migrations' => array(
      'MotivationCallProduct' => array(
        'machine_name' => 'MotivationCallProduct',
        'class_name' => 'MotivationCallProduct',
        'group_name' => 'motivation_call',
      ),
    ),
  );
  return $api;
}