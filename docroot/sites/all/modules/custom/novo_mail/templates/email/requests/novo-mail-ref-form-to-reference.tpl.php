<?php

/**
 * @file
 * Email template.
 */
?>
<p> Hello, <?php print $params['ref_name']; ?>,</p>

<p>
  <?php print $params['app_first_name']; ?> <?php print $params['app_last_name']; ?>
    recently applied to become a volunteer at Novo and has provided your name as
    a personal reference. We're an Oklahoma City nonprofit organization that
    connects the faith-community to inner-city boys and girls with the purpose
    of introducing them and growing them in their relationship with Christ.
    Volunteers
    like <?php print $params['app_first_name']; ?> <?php print $params['app_last_name']; ?>
    are a huge part in reaching Oklahoma
    City with the Gospel!</br>
    Our reference form takes about 3 minutes to complete on our secure and
    confidential reference for at <?php print $params['link']; ?>. Please
    complete this
    form within 3 days of receiving, because the link will expire after 72
    hours.</p>

<p>If you have any questions, please contact us at 405.208.4255 or by email at
  <?php print NOVO_MAIL_BASE_EMAIL_FOR_REPLACE_TEMPLATE; ?></p>

<p>Thank you for your time and help! Novo Staff Team</p>
