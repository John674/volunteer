<?php

/**
 * @file
 * Novo dynamic fields row theme.
 */
?>

<div class="row field">
    <div class="col-md-6">
      <?php if (!empty($title)): ?>
          <div class="field-label"><span><?php print $title; ?>:</span></div>
      <?php endif; ?>
    </div>
    <div class="col-md-6">
        <span><?php print $content; ?></span>
    </div>
</div>
