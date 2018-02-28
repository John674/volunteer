<?php

/**
 * @file
 * Email template.
 */
?>

<p><?php print $params['app_first_name']; ?> <?php print $params['app_last_name']; ?> is turning 18 on (<?php print $params['dob_date']; ?>). </p>

<p>Verify if the volunteer is active. Mark the
    volunteer's name accordingly in the database. If active, a birthday email
    will be triggered accordingly with the background consent link/form to the
    volunteer on his/her birthday.</p>
