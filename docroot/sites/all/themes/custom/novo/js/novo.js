/**
 * Created by svipsa on 17.06.17.
 */
(function ($) {
    Drupal.behaviors.Novo = {
        attach: function (context, settings) {
            $('.selectpicker').selectpicker('refresh');
            ChangeNamePublishToActive();

            // $(".field-name-field-program-staff-list select", context).selectpicker({
            //     liveSearch: true,
            //     selectedTextFormat: 'count > 3'
            // });
            function ChangeNamePublishToActive() {
                var $publish_btn = $('#edit-publish');
                if ($publish_btn.val() == 'Publish') {
                    $publish_btn.text('Active');
                } else {
                    $publish_btn.text('Not active');
                }
            }
        }
    };
})(window.jQuery);