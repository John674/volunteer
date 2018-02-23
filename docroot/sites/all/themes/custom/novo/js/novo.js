/**
 * Created by svipsa on 17.06.17.
 */
(function ($) {
    Drupal.behaviors.Novo = {
        attach: function (context, settings) {
            $('.selectpicker').selectpicker('refresh');
            // $(".field-name-field-program-staff-list select", context).selectpicker({
            //     liveSearch: true,
            //     selectedTextFormat: 'count > 3'
            // });

            $("button.btn-success:not(.icon-before)").addClass("icon-before").prepend('<span class="icon glyphicon glyphicon-ok" aria-hidden="true"></span>');

            var current_year = new Date().getFullYear();

            if ($(".field-name-field-dob input", context).length) {
                $(".field-name-field-dob input", context).datepicker({
                    maxDate: new Date(),
                    changeMonth: true,
                    changeYear: true,
                    yearRange: (current_year - 100) + ":" + current_year
                });
            }

            if ($(".field-name-field-u-birthday input", context).length) {
                $(".field-name-field-u-birthday input", context).datepicker({
                    maxDate: new Date(),
                    changeMonth: true,
                    changeYear: true,
                    yearRange: (current_year - 100) + ":" + current_year
                });
            }

            // Hover main menu.
            $('.navbar-nav .dropdown a.dropdown-toggle', context).on('click', function() {
              location.href = $(this).attr('href');
            });
        }
    };
})(window.jQuery);