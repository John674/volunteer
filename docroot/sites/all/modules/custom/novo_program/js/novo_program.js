/**
 * @file
 * Javascript for Color Field.
 */
(function ($) {
  "use strict";

  Drupal.behaviors.novoProgram = {
    attach: function (context) {
      var self = this;

      // First load.
      $(".field-name-field-program-kids-list table.field-multiple-table", context).find(".field-name-field-p-kid-name input.form-text").each(function (el) {
        $(this).parents(".field-p-kid-name").find(".novo-program-kid-data").remove();
        $(this).parents(".field-p-kid-name").append($('<span class="novo-program-kid-data"><i class="glyphicon glyphicon-refresh glyphicon-spin"></i></span>'));
        var selected_nid = $(this).val();
        self.novoProgramGetKidData(selected_nid, $(this));
      });

      // Add labels.
      $(".field-name-field-program-kids-list table.field-multiple-table thead tr th:eq(4)", context).once().append('<span class="novo-program-kid-data-header"><span class="novo-program-kid-data-header-age">Age</span> <span class="novo-program-kid-data-header-grade">Grade</span></span>');
      $(".field-name-field-program-kids-list table.sticky-header thead tr th:eq(4)", context).once().append('<span class="novo-program-kid-data-header"><span class="novo-program-kid-data-header-age">Age</span> <span class="novo-program-kid-data-header-grade">Grade</span></span>');

      // On change.
      $(".field-name-field-p-kid-name input.form-text", context).once().on('change', function (e) {
        $(this).parents(".field-p-kid-name").find(".novo-program-kid-data").remove();
        $(this).parents(".field-p-kid-name").append($('<span class="novo-program-kid-data"><i class="glyphicon glyphicon-refresh glyphicon-spin"></i></span>'));

        var selected_nid = $(this).val();
        self.novoProgramGetKidData(selected_nid, $(this));
      });
    },
    novoProgramGetKidData: function (selected_nid, el) {
      if (selected_nid) {
        $.ajax({
          method: 'GET',
          url: Drupal.settings.basePath + 'novo-program/get-kid-data/' + selected_nid,
          success: function (data) {
            if (data) {
              el.parents(".field-p-kid-name").find(".novo-program-kid-data").remove();
              el.parents(".field-p-kid-name").append(data);
            }
          },
          error: function (data) {
            el.parents(".field-p-kid-name").find(".novo-program-kid-data").remove();
          }
        });
      }
      else {
        el.parents(".field-p-kid-name").find(".novo-program-kid-data").remove();
      }
    }
  };
})(jQuery);