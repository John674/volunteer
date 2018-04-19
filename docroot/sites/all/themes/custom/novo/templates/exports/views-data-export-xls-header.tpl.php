<?php

/**
 * @file
 * Theme export XLS header.
 */
?>

<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
</head>
<body>

<table>
    <tbody>
    <tr>
        <td colspan="<?php print isset($header) ? count($header) : "5"; ?>"
            style="height: 52px;">
            <div class="report-header-left">
              <?php print theme('image', [
                'path' => drupal_get_path("theme", "novo") . "/images/novo_export_logo.png",
                'width' => 150,
                'height' => 52,
                'attributes' => array("style" => "margin:5px; padding:5px")
              ]);
              ?>
            </div>
            <div class="report-header-right"
                 style="background-color:red; width=100%; text-align: right">
                <div class="report-name"><?php print $view->human_name; ?></div>
                <div><?php print t("Report Date:") . " " . format_date(REQUEST_TIME, "custom", "m/d/Y"); ?></div>
            </div>
        </td>
    </tr>
    </tbody>
</table>

<table>
  <?php print $header_row; ?>
    <tbody>
