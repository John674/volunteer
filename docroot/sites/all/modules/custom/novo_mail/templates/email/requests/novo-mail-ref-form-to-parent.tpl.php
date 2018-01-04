<?php

/**
 * @file
 * Email template.
 */
?>

<p>Dear <?php print $params['ref_name']; ?></p>

<p><?php print $params['app_first_name']; ?> <?php print $params['app_last_name']; ?>
    has applied to volunteer with our organization. All volunteers under 18
    years of age require approval from a parent or guardian in order for us to
    begin processing their volunteer application. Please click here
  <?php print $params['link']; ?> to consent.</p>

<p>Thank you, The Novo Team</p>