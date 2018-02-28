<?php

/**
 * @file
 * Email template.
 */
?>

<p>
    Hi, <?php print $params['app_first_name']; ?> <?php print $params['app_last_name']; ?>,</p>
<p>We are excited about your interest in serving at Novo! We noticed you
    recently started your online application. Please complete your application
    by going here: <?php print $params['site_link']; ?> </p>

<p>If you have any questions or experienced any issues completing your
    application, please email us at: <?php print NOVO_MAIL_BASE_EMAIL_FOR_REPLACE_TEMPLATE; ?> or call us at
    405.208.4255 during regular business hours.
    We're excited to partner together to bring HOPE to inner-city boys and
    girls!</p>

<p>The Novo Staff</p>
