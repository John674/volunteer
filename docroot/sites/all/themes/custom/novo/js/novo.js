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

        }
    };
})(jQuery);