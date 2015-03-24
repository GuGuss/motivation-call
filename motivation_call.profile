<?php

/**
 * Implements hook_install()
 */
function motivation_call_install() {
  // Enable Bootstrap Business theme.
  theme_enable(array('bootstrap_business'));
  variable_set('theme_default', 'bootstrap_business');

  // Set the admin theme.
  db_update('system')
    ->fields(array('status' => 1))
    ->condition('type', 'theme')
    ->condition('name', 'seven')
    ->execute();
  variable_set('admin_theme', 'seven');

  // Set the site's front page.
  variable_set('site_frontpage', 'home');
}
