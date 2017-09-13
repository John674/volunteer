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
<?php
if (!$logo = theme_get_setting('logo_path')) {
  $logo = theme_get_setting('logo');
}
?>

<?php if ($logo): ?>
    <table>
        <tbody>
        <tr>
            <td colspan="<?php print isset($header) ? count($header) : "5"; ?>"
                style="background: #626463; height: 40px;">
              <?php print theme('image', array('path' => $logo)); ?>
            </td>
        </tr>
        </tbody>
    </table>
<?php endif; ?>
<table>
  <?php print $header_row; ?>
    <tbody>
