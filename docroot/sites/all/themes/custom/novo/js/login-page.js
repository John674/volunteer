/**
 * Created by svipsa on 17.06.17.
 */
(function ($) {
    Drupal.behaviors.Novo = {
        attach: function (context, settings) {
            $('.fullscreen-slider').carousel();
        }
    };
})(window.jQuery);