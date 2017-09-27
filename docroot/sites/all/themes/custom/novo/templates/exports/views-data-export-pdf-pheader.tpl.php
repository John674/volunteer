<?php

/**
 * @file
 * Theme export page header.
 */
?>
<!doctype html>
<html>
<head>
    <style>
        .report-header {
            width: 100%;
            overflow: hidden;
            display: block;
        }
        .report-header-left,
        .report-header-right {
            margin: 20px 0px 10px 0px;
            width: 50%;
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
        table {
            overflow-wrap: break-word;
        }
        tr {
            page-break-inside: avoid !important;
        }
    </style>
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
</body>
</html>