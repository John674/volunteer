<?php

/**
 * @file
 * Theme export page header.
 */
?>

<div class="report-header" style="width: 100%; overflow: hidden; display: block;">
    <div class="report-header-left" style="margin: 20px 0px 10px 0px;width: 50%;float: left;">
      <?php print theme('image', [
        'path' => drupal_get_path("theme", "novo") . "/images/novo_export_logo.png",
        'width' => 100,
      ]); ?>
    </div>

    <div class="report-header-right" style="margin: 20px 0px 10px 0px;width: 50%;float: left; text-align: right;">
        <div class="report-name" style="font-size: 16px;"><?php print $view->human_name; ?></div>
        <div><?php print t("Report Date:") . " " . format_date(REQUEST_TIME, "custom", "m/d/Y"); ?></div>
    </div>
</div>
