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

            if ($(".field-name-field-dob input", context).length) {
                $(".field-name-field-dob input", context).datepicker({
                    maxDate: new Date(),
                });
            }

        }
    };
})(window.jQuery);