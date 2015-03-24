<?php
/**
 * @file
 * store_configuration.features.inc
 */

/**
 * Implements hook_commerce_product_default_types().
 */
function store_configuration_commerce_product_default_types() {
  $items = array(
    'motivation_call' => array(
      'type' => 'motivation_call',
      'name' => 'Motivation Call',
      'description' => '',
      'help' => '',
      'revision' => 1,
    ),
  );
  return $items;
}

/**
 * Implements hook_commerce_tax_default_rates().
 */
function store_configuration_commerce_tax_default_rates() {
  $items = array(
    'tva_20' => array(
      'name' => 'tva_20',
      'display_title' => 'TVA 20%',
      'description' => '',
      'rate' => 0.2,
      'type' => 'vat',
      'rules_component' => 'commerce_tax_rate_tva_20',
      'default_rules_component' => 1,
      'price_component' => 'tax|tva_20',
      'calculation_callback' => 'commerce_tax_rate_calculate',
      'module' => 'commerce_tax_ui',
      'title' => 'TVA 20',
      'admin_list' => TRUE,
    ),
  );
  return $items;
}

/**
 * Implements hook_views_api().
 */
function store_configuration_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
