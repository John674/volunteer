/**
 * @file
 * Javascript for Datepicker.
 */
(function ($) {
  "use strict";

  Drupal.behaviors.novoApplicationsHandlerAppActiveStatusOnDateDilter = {
    attach: function (context) {
      $(".form-item-novo-application-active-status-on-date input", context).datepicker();


      var addon = $('<label class="novo-reports-filter-on-date-icon input-group-addon btn" for="edit-novo-application-active-status-on-date"><span class="glyphicon glyphicon-calendar" aria-hidden="true"></span></label>');
      $(".form-item-novo-application-active-status-on-date input", context).parents(".views-widget").append(addon);
    }
  };
})(jQuery);