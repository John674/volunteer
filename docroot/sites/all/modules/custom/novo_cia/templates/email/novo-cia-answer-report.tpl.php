<?php

/**
 * @file
 * CIA email theme.
 */
?>

<p>Hello <?php print $params['reviewer_name'];?>,</p>


<?php if (isset($params['cia_answer']) && $params['cia_answer'] == 'positive'): ?>
    No issues were found in the background check for: <?php print $params['vol_name']; ?>
    Login at volunteer.novoministries.org to continue the approval process.
  <?php print $params['vol_link']; ?>
<?php else: ?>
    An issue was found in the background check for: <?php print $params['vol_name']; ?>
    Login at volunteer.novoministries.org to review the issue and determine next steps.
  <?php print $params['vol_link']; ?>
<?php endif; ?>
