/**
 *  @file
 *  Initiate the BxSlider plugin.
 */

(function ($) {
  Drupal.behaviors.viewsSlideshowBxslider = {
    attach: function (context, settings) {
      for (id in Drupal.settings.viewsSlideshowBxslider) {
        $('#' + id + ':not(.viewsSlideshowBxslider-processed)', context).addClass('viewsSlideshowBxslider-processed').each(function () {
          var settings = Drupal.settings.viewsSlideshowBxslider[$(this).attr('id')];
          // Fire up the gallery.
          $(this).bxSlider(settings);
        });
      }
    }
  };
}(jQuery));
