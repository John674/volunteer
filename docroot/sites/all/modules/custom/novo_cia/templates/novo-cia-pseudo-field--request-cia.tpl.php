<?php

/**
 * @file
 * Pseudo field request cia.
 */
?>

<?php if(!empty($cia_data)):?>
    <div class="row field">
        <div class="col-md-6">
          <?php print $cia_data['title']; ?>
        </div>
        <div class="col-md-3">
          <?php print $cia_data['status_label']; ?>
        </div>
        <div class="col-md-3">
          <?php if (isset($cia_data['status_buttons'])): ?>
            <?php print $cia_data['status_buttons']; ?>
          <?php endif; ?>
        </div>
    </div>
    <hr>
<?php endif;?>
