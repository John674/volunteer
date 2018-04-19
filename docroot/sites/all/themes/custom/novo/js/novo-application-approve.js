/**
 * Created by svipsa on 17.06.17.
 */
(function ($) {
    Drupal.behaviors.NovoApplicationApprove = {
        attach: function (context, settings) {
            $('.novo-application-approve-btn', context).confirmation({
                singleton: "true",
                popout: "true",
                btnOkClass: "btn-success btn-xs",
                btnCancelClass: "btn-danger btn-xs",
            });
        }
    };
})(window.jQuery);