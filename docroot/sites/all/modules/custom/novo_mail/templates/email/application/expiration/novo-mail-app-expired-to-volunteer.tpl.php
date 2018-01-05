<?php

/**
 * @file
 * Email template.
 */
?>

<p>Hello, <?php print $params['app_first_name'];?> <?php print $params['app_last_name'];?>,</p>

<p>Our records indicate that your background check for serving in Novo Programs is about to expire.</p>
<p>Please go on site volunteer.novoministries.org and update your personal information that may have changed since we last ran a background check.</p>
<p>Simply follow the link, update any information that has changed, and provide permission for us to run a new background check. That’s it! We take care of the rest.</p>
<p><?php print $params['link'];?></p>
<p>Thank you for volunteering with us!</p>
<p>The Novo Staff</p>
