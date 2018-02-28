<?php

/**
 * @file
 * Email template.
 */
?>

<p><?php print $params['app_first_name'];?> <?php print $params['app_last_name'];?>'s background check has expired.</p>

<p>First, verify that the volunteer is active.</p>

<p><?php print $params['link'];?></p>

<p>If active, send the volunteer’s consent email. Once permission is granted, run the background check.</p>

<p>f inactive, mark volunteer as inactive, and no further action is necessary.
    All tasks related to that volunteer will automatically be removed from the
    Background Tasks list.
    You can review his address data yourself, or resend request email to him on
    site <?php print $params['site_link']; ?></p>
