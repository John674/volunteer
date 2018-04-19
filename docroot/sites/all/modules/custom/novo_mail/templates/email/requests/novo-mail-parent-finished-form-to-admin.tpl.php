<?php

/**
 * @file
 * Email template.
 */
?>

<p>
  <?php print $params['app_first_name']; ?> <?php print $params['app_last_name']; ?>
    has received parental permission for application.</p>
<p>
    Login at <?php print $params['site_link']; ?> to view this approval.
</p>
