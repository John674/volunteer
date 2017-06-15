<?php

/**
 * @file
 * Default theme Frontpage welcome block.
 */
?>
<div class="container">

  <?php
  $already_created_app = isset($data['#content']['already_created_app']) ? $data['#content']['already_created_app'] : FALSE;
  ?>


  <?php if ($already_created_app) : ?>
      <h2>ALREADY CREATED</h2>
  <?php endif; ?>

    Welcome, Sergey(Test) Ivanov!
    Your application will begin processing now! We will keep you updated on our
    progress by email, and please feel free to contact us at anytime for more
    information (volunteer@novoministries.org or 405.208.4255).

    We generally complete volunteer applications in 3 - 7 days.

    We’re so excited to work together to introduce the boys and girls of
    Oklahoma City to Jesus Christ. Thank you!

    Made a mistake on your application?
</div>
