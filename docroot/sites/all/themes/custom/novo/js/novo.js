/**
 * Created by svipsa on 17.06.17.
 */
(function ($) {
    Drupal.behaviors.Novo = {
        attach: function (context, settings) {
            $('.selectpicker').selectpicker('refresh');
        }
    };
})(jQuery);