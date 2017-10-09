<?php

/**
 * @file
 * CIA email theme.
 */
?>

<p>Hello <?php print $params['reviewer_name'];?>,</p>
<p>CIA Answer is <?php print $params['cia_answer']; ?> for <?php print $params['vol_name']; ?>, please open Novo Volunteer <a target="_blank" href="<?php print $params['vol_link'] ?>">system</a>.</p>
<p>Thanks.</p>
