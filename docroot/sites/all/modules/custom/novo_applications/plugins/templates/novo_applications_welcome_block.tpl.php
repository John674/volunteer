<?php

/**
 * @file
 * Default theme Frontpage welcome block.
 */
?>
<div class="container">
    <div class="row">
      <?php
      $already_created_app = isset($data['#content']['already_created_app']) ? $data['#content']['already_created_app'] : FALSE;
      $user_name = isset($data['#content']['user_name']) ? $data['#content']['user_name'] : "";
      ?>

        <div class="panel panel-default">
            <div class="panel-heading">Welcome, <?php print $user_name; ?>!
            </div>

            <div class="panel-body">

              <?php if ($already_created_app) : ?>
                  <p>
                    <?php
                    print t("Your application will begin processing now! We will keep you updated on our progress by email, and please feel free to contact us at anytime for more information (!email or !phone)",
                      array(
                        "!email" => l(NOVO_BASE_EMAIL, "mailto:" . NOVO_BASE_EMAIL),
                        "!phone" => l(NOVO_BASE_PHONE_LABEL, "tel:" . NOVO_BASE_PHONE)
                      ));
                    ?>
                  </p>
                  <p><?php print t("We generally complete volunteer applications in 3 - 7 days."); ?></p>
                  <p>
                    <?php print t("We’re so excited to work together to introduce the boys and girls of Oklahoma City to Jesus Christ. Thank you!"); ?>
                  </p>

                  <div>
                      <a data-toggle="collapse" class="black-link"
                         href="#collapseMistake">
                          <span class="glyphicon glyphicon-question-sign"></span><span
                                  style="margin-left: 5px;"><?php print t("Made a mistake on your application?"); ?></span>
                      </a>

                      <div id="collapseMistake" class="panel-collapse collapse">
                          <div class="panel-body">
                            <?php
                            print t("Please email !email or call us at !phone and we will assist you in correcting your application.",
                              array(
                                "!email" => l(NOVO_BASE_EMAIL, "mailto:" . NOVO_BASE_EMAIL),
                                "!phone" => l(NOVO_BASE_PHONE_LABEL, "tel:" . NOVO_BASE_PHONE)
                              ));
                            ?>
                          </div>
                      </div>
                  </div>
              <?php else: ?>

                  <p>
                    <?php print t("Your are in progress of completing Application Form. Please continue."); ?>
                  </p>

                  <div class="col-md-12 center-block  user-button">
                    <?php print l(t("Continue Application"), "node/add/application", array(
                      "attributes" => array(
                        "role" => "button",
                        "class" => array("btn", "btn-primary")
                      )
                    )); ?>
                  </div>

                  <div>
                      <a data-toggle="collapse" class="black-link"
                         href="#collapseMistake">
                          <span class="glyphicon glyphicon-question-sign"></span><span
                                  style="margin-left: 5px;"><?php print t("Made a mistake on your application?"); ?></span>
                      </a>

                      <div id="collapseMistake" class="panel-collapse collapse">
                          <div class="panel-body">
                            <?php
                            print t("Please email !email or call us at !phone and we will assist you in correcting your application.",
                              array(
                                "!email" => l(NOVO_BASE_EMAIL, "mailto:" . NOVO_BASE_EMAIL),
                                "!phone" => l(NOVO_BASE_PHONE_LABEL, "tel:" . NOVO_BASE_PHONE)
                              ));
                            ?>
                          </div>
                      </div>
                  </div>
                  <div>
                      <a data-toggle="collapse" class="black-link collapsed"
                         href="#collapseProfile" aria-expanded="false">
                          <span class="glyphicon glyphicon-question-sign"></span><span
                                  style="margin-left: 5px;"><?php print t("Need to update your profile?"); ?></span>
                      </a>

                      <div id="collapseProfile" class="panel-collapse collapse"
                           aria-expanded="false" style="height: 0px;">
                          <div class="panel-body">
                            <?php print l(t("You can update your info here"), "node/add/application"); ?>
                          </div>
                      </div>
                  </div>


              <?php endif; ?>
            </div>
        </div>
    </div>

  <?php if ($already_created_app) : ?>
      <div class="row">
          <div class="col-md-10 col-md-offset-1">
              <div class="training-invite">
                  <h1><?php print t("Want to get ahead? Complete the required training!"); ?></h1>
                  <h2><?php print t("(It only takes 30 minutes)"); ?></h2>
                <?php print l(t("Begin training"), "https://novoministries.org/training_video/module-1-orientation/", array(
                  "esternal" => TRUE,
                  "attributes" => array("class" => array("btn", "btn-primary"))
                )); ?>

              </div>
          </div>
      </div>
  <?php endif; ?>


</div>
