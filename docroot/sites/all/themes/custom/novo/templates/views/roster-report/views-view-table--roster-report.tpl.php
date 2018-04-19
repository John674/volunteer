<?php

/**
 * @file
 * Template to display a view as a table.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $header: An array of header labels keyed by field id.
 * - $caption: The caption for this table. May be empty.
 * - $header_classes: An array of header classes keyed by field id.
 * - $fields: An array of CSS IDs to use for each field id.
 * - $classes: A class or classes to apply to the table, based on settings.
 * - $row_classes: An array of classes to apply to each row, indexed by row
 *   number. This matches the index in $rows.
 * - $rows: An array of row items. Each row is an array of content.
 *   $rows are keyed by row number, fields within rows are keyed by field ID.
 * - $field_classes: An array of classes to apply to each field, indexed by
 *   field id, then row number. This matches the index in $rows.
 * @ingroup views_templates
 */

$moved_flag_first = FALSE;
?>
<table <?php if ($classes) {
  print 'class="' . $classes . '" ';
} ?><?php print $attributes; ?>>
  <?php if (!empty($title) || !empty($caption)) : ?>
      <caption><?php print $caption . $title; ?></caption>
  <?php endif; ?>
  <?php if (!empty($header)) : ?>
      <thead>
      <tr>
        <?php foreach ($header as $field => $label): ?>
            <th <?php if ($header_classes[$field]) {
              print 'class="' . $header_classes[$field] . '" ';
            } ?> scope="col">
              <?php print $label; ?>
            </th>
        <?php endforeach; ?>
      </tr>
      </thead>
  <?php endif; ?>
    <tbody>
    <?php foreach ($rows as $row_count => $row): ?>
      <?php
      $moved = ($result[$row_count]->node_field_data_field_p_kid_name__field_data_field_moved_fie);
      $moved_class = ($moved) ? "row-kid-moved" : "";
      ?>

      <?php if ($moved && !$moved_flag_first) : ?>
      <?php $moved_flag_first = TRUE; ?>
        <tr class="row-kid-moved-header-margin"><td colspan="<?php print count($row);?>">&nbsp;</td></tr>
        <tr class="row-kid-moved-header">
            <td colspan="<?php print count($row);?>"><?php print t("Moved");?></td>
        </tr>
      <?php endif; ?>

        <tr <?php if ($row_classes[$row_count]) {
          print 'class="' . implode(' ', $row_classes[$row_count]) . ' ' . $moved_class . '"';
        } ?>>
          <?php foreach ($row as $field => $content): ?>
              <td <?php if ($field_classes[$field][$row_count]) {
                print 'class="' . $field_classes[$field][$row_count] . '" ';
              } ?><?php print drupal_attributes($field_attributes[$field][$row_count]); ?>>
                <?php print $content; ?>
              </td>
          <?php endforeach; ?>
        </tr>
    <?php endforeach; ?>
    </tbody>
</table>
