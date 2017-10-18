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

        .field-collection-item-field-parent-guardian .field {
            float: left;
            display: inline-block;
            margin-right: 5px;
        }
    </style>
  <?php print (isset($head) && !empty($head)) ? $head : ""; ?>
</head>
<body>
