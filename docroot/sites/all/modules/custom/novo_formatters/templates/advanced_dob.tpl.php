<?php

/**
 * @file
 * Template for date and age.
 */
?>
<p><?php print ($dob) ?> <span>
    <?php if (!empty($advanced_text)): ?>
        (<?php print $advanced_text; ?>)
    <?php endif; ?></span>
</p>
