<?php

/**
 * @file
 * Theme export PDF header.
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
