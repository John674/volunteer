<?php

/**
 * @file
 * Email template.
 */
?>
<p> Hello <?php print $params['ref_name']; ?></p>

<p>
  <?php print $params['app_first_name']; ?> <?php print $params['app_last_name']; ?>
    recently applied to become a
    volunteer at Novo and has provided your name as a church reference. We're an
    Oklahoma City nonprofit organization that connects the faith-community to
    inner-city boys and girls with the purpose of introducing them and growing
    them in their relationship with Christ. Volunteers
    like <?php print $params['app_first_name']; ?> <?php print $params['app_last_name']; ?>
    are a huge part in reaching Oklahoma City with the Gospel!
    Our reference form takes about 3 minutes to complete on our secure and
    confidential refernece form at <?php print $params['link']; ?>.
</p>

<p>If you have any questions, please contact us at 405.208.4255 or by email at
    volunteer@novoministries.org</p>

<p>Thank you for your time and help! Novo Staff Team</p>