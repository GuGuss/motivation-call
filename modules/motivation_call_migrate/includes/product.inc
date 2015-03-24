<?php
class MotivationCallProduct extends Migration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('CSV import of the products.');

    // Create a map object for tracking the relationships between source rows.
    $this->map = new MigrateSQLMap(
      $this->machineName, 
      array(
        'title_csv' => array('type'=>'varchar', 'length'=>255, 'not null'=>TRUE,),
      ),
      MigrateDestinationEntityAPI::getKeySchema('commerce_product')
    );

    // Create a MigrateSource object.
    $this->source = new MigrateSourceCSV(
      drupal_get_path('module', 'motivation_call_migrate').'/csv/product.csv', 
      $this->csvcolumns(), 
      array('header_rows' => 1)
    );

    // The destination bundle.
    $this->destination = new MigrateDestinationEntityAPI('commerce_product', 'motivation_call');

    // Field mapping.
    $this->addFieldMapping('sku', 'sku_csv');
    $this->addFieldMapping('title', 'title_csv');
    $this->addFieldMapping('commerce_price', 'price_csv');
    $this->addFieldMapping('commerce_price:currency_code')->defaultValue('EUR');
    $this->addFieldMapping('commerce_price:tax_rate')->defaultValue('tva_20');
    $this->addFieldMapping('field_image', 'image_csv');
    $this->addFieldMapping('field_image:file_replace')->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_image:source_dir')->defaultValue(drupal_get_path('module', 'motivation_call_migrate') . '/images');
    $this->addFieldMapping('uid', 'uid')->defaultValue(1);
  }

  function csvcolumns() {
    // The defintion of the columns. Keys are integers. values are array(field name, description).
    $columns[0] = array('sku_csv', 'SKU');
    $columns[1] = array('title_csv', 'Title');
    $columns[2] = array('price_csv', 'Price');
    $columns[3] = array('image_csv', 'Image');
    return $columns;
  }
}