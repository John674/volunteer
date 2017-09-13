<?php

/**
 * @file
 * Novo dynamic fields row theme.
 */
?>

<div class="panel panel-default novo-dynamic-fields-form-container">
  <?php if (!empty($title)): ?>
      <div class="panel-heading"><?php print $title; ?></div>
  <?php endif; ?>
    <div class="panel-body">
      <?php print $content; ?>
    </div>
</div>
