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
        body {
            font-family: verdana;
            font-size: 14px;
        }
        table td, table th {
            border: 1px solid #9d9ea5;
        }
        th {
            background: #c9c9c9;
        }
        tr:nth-child(even) {
            background: #f1f1f1
        }
        tr:nth-child(odd) {
            background: #fff
        }
        .report-header {
            width: 100%;
        }
        .report-header-left,
        .report-header-right {
            margin: 20px 0px; width: 50%;
            float: left;
        }
        .report-header-right {
            text-align: right;
        }
        .report-name {
            font-size: 16px;
        }
        .field-collection-item-field-parent-guardian .field {
            float: left;
            display: inline-block;
            margin-right: 5px;
        }

    </style>
  <?php print (isset($head) && !empty($head)) ? $head : ""; ?>
</head>
<body>

<div class="report-header">
    <div class="report-header-left">
      <?php print theme('image', [
        'path' => drupal_get_path("theme", "novo") . "/images/novo_export_logo.png",
        'width' => 100,
      ]); ?>
    </div>

    <div class="report-header-right">
        <div class="report-name"><?php print $view->human_name; ?></div>
        <div><?php print t("Report Date:") . " " . format_date(REQUEST_TIME, "custom", "m/d/Y"); ?></div>
    </div>

</div>

<table border="0" cellpadding="5" cellspacing="0" width="100%">
  <?php print $header_row; ?>
    <tbody>
