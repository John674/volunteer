<?php

/**
 * @file
 * Template for nametag of kid.
 */
?>

<div class="rotatable nametag-block">

    <div class="nametag-row nametag-row-big">
      <?php print $data['apt']; ?>
      <?php print $data['address_1']; ?>
      <?php print $data['address_2']; ?>
    </div>
    <div class="nametag-row">
      <?php print $data['city']; ?>
      <?php print $data['state']; ?>
      <?php print $data['zip']; ?>
    </div>

    <div class="nametag-row-parent-pickup">
        <div class="nametag-row-label"><?php print t("Parent / Guardian"); ?></div>
        <div class=""><?php print $data['parent']; ?></div>

      <?php if (!empty($data['pickup_contacts'])): ?>
          <div class="nametag-row-label nametag-row-label-second"><?php print t("Pickup / Emergency"); ?></div>
          <div class=""><?php print $data['pickup_contacts']; ?></div>
      <?php endif; ?>
    </div>
    <div class="nametag-row"><?php print $data['location']; ?></div>

</div>

<div class="nametag-block">

    <div class="nametag-row nametag-row-big"><?php print $data['no_photo']; ?></div>
    <div class="nametag-row nametag-row-b1"><?php print $data['first_name']; ?></div>
    <div class="nametag-row nametag-row-b2"><?php print $data['last_name']; ?></div>
    <div class="nametag-row nametag-row-b2"><?php print $data['small_group']; ?></div>


    <div class="nametag-row nametag-row-b1 nametag-dismissal"
         style="<?php print (isset($data['canvassing_group_color']) && !empty($data['canvassing_group_color'])) ? "color:" . $data['canvassing_group_color'] : ""; ?>"><?php print $data['dismissal']; ?></div>
    <div class="nametag-row nametag-canvassing"><?php print $data['canvassing_group']; ?></div>

    <div class="nametag-row nametag-row-allergies">
        <div class="nametag-row-allergies-wrapper">
          <?php print $data['food_allergies']; ?>
        </div>
    </div>
    <div class="nametag-row"><?php print $data['location']; ?></div>
</div>