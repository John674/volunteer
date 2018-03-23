/**
 * @file
 * Javascript for Color Field.
 */
(function ($) {
  "use strict";

  Drupal.behaviors.novoProgram = {
    attach: function (context) {
      var self = this;


      if (context instanceof jQuery && context.attr("id") &&  context.attr("id").indexOf("field-p-kids-pickup-contacts-add-more-wrapper") >= 0) {
        // set focus.
        context.find(".field-multiple-table tr:last input[type='text']:first").focus();
      }

      // First load. Load all items per one request.
      var selected_nids_data = [];
      $(".field-name-field-program-kids-list table.field-multiple-table", context).once().find(".field-name-field-p-kid-name input.form-text").each(function (el) {
        $(this).parents(".field-p-kid-name").find(".novo-program-kid-data").remove();
        $(this).parents(".field-p-kid-name").append($('<span class="novo-program-kid-data"><i class="glyphicon glyphicon-refresh glyphicon-spin"></i></span>'));
        var selected_nid = $(this).val();
        if (selected_nid) {
          selected_nids_data.push({
            "nid_string": selected_nid,
            "el": $(this)
          });
        } else {
          $(this).parents(".field-p-kid-name").find(".novo-program-kid-data").remove();
        }
      });
      if (selected_nids_data.length) {
        self.novoProgramGetKidDataAll(selected_nids_data);
      }

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
    novoProgramGetKidDataAll: function (selected_nids_data) {
      if (selected_nids_data.length) {
        var self = this,
            data = [];

        for (var n in selected_nids_data) {
            data.push(selected_nids_data[n].nid_string);
        }

        $.ajax({
          method: 'POST',
          url: Drupal.settings.basePath + 'novo-program/get-kid-data-all',
          data: {nids: data},
          success: function (result) {
            if (data) {
              for (var n in result) {
                var el = self.getElFromString(n, selected_nids_data);
                if (el) {
                  $(el).parents(".field-p-kid-name").find(".novo-program-kid-data").remove();
                  $(el).parents(".field-p-kid-name").append(result[n]);
                }
              }
            }
          },
          error: function (data) {

          }
        });
      }
    },

    getElFromString: function (nid_string, selected_nids_data) {
      for (var n in selected_nids_data) {
        if (selected_nids_data[n].nid_string == nid_string) {
          return selected_nids_data[n].el;
        }
      }
      return null;
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