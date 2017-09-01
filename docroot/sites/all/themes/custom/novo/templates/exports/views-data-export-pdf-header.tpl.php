<?php

/**
 * @file
 * Theme export DPF header.
 */
?>

<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <style>
        table td, table th {
            border: 1px solid #ccc;
        }
    </style>
  <?php print (isset($head) && !empty($head)) ? $head : ""; ?>
</head>
<body>

<?php
if (!$logo = theme_get_setting('logo_path')) {
  $logo = theme_get_setting('logo');
}
?>
<?php if ($logo): ?>
    <div style="background: #626463; margin: 20px; 0px; padding: 10px; width:100%;">
      <?php print theme('image', array('path' => $logo)); ?>
    </div>
<?php endif; ?>

<table border="0" cellpadding="5" cellspacing="0">
  <?php print $header_row; ?>
    <tbody>
