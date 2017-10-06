<?php

/**
 * @file
 * CIA email theme.
 */
?>

<p>Hello <?php print $params['reviewer_name'];?>,</p>
<p>Volunteer <?php print $params['vol_name']; ?> was expired, please open Novo Volunteer <a target="_blank" href="<?php print $params['vol_link'] ?>">system</a>.</p>
<p>Thanks.</p>
