<?php

/**
 * @file
 * Ref request email theme.
 */
?>

<p><?php print $params['app_first_name'];?> <?php print $params['app_last_name'];?>'s background check has expired.</p>

<p>First, verify that the volunteer is active.</p>

<p><?php print $params['link'];?></p>

<p>If active, send the volunteer’s consent email. Once permission is granted, run the background check.</p>

<p>If inactive, mark volunteer as inactive, and no further action is necessary.</p>