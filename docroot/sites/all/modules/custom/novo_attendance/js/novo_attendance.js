/**
 * @file
 * Javascript for Color Field.
 */
(function ($) {
    "use strict";

    Drupal.behaviors.novoAttendance = {
        attach: function (context) {
            var self = this;
            self.set_format_date(context);
            $(".field-name-field-attendance-year select", context).on("change", function () {
                self.set_format_date($(".node-attendance-form"));
            });
        },

        set_format_date: function (context) {
            var selected_date = $(".field-name-field-attendance-year select option:selected", context).val();
            if (selected_date) {
                $(".field-name-field-attendance-date input", context).datepicker("destroy");
                var start_date = new Date(parseInt(selected_date), 7, 1);
                // var end_date = new Date(parseInt(selected_date) + 1, 6, 31);
                var end_date = new Date();

                $(".field-name-field-attendance-date input", context).datepicker({
                    minDate: start_date,
                    maxDate: end_date,
                    defaultDate: end_date
                });
            }
        }
    };
})(jQuery);
