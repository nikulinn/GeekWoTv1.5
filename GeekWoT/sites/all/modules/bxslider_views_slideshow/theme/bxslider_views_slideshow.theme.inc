<?php
/**
 * @file
 * The theme system that controls the display of Views Slideshow: Bxslider.
 */

/**
 *  Process variables for views-bxslider-main-frame.tpl.php.
 */
function template_preprocess_bxslider_views_slideshow_main_frame(&$vars) {
  _bxslider_views_slideshow_add_js($vars['settings'], 'views-slideshow-bxslider-images-' . $vars['id']);

  $vars['classes_array'][] = 'bxslider';

  $rendered_rows = '';
  foreach ($vars['rows'] as $count => $item) {
    _bxslider_views_slideshow_set_extra_css($vars['settings']['align_image']);
    $rendered_rows[] = theme('bxslider_views_slideshow_main_frame_row', array(
      'vss_id' => $vars['vss_id'], 'items' => $item, 'count' => count($vars['rows']), 'view' => $vars['view']));
  }
  $vars['rendered_rows'] = $rendered_rows;
}

function _bxslider_views_slideshow_set_extra_css($align_image) {
  $selector = ".views-slideshow-bxslider li img";
  switch($align_image) {
    case 'center':
      drupal_add_css($selector . ' { margin-left:auto; margin-right:auto; }', 'inline');
      break;
    case 'right':
      drupal_add_css($selector . ' { margin-left:auto; }', 'inline');
      break;
    default:
      drupal_add_css($selector . ' { margin-right:auto; }', 'inline');
  }
}

/*
 * Helper function to build and pass BxSlider settings to Drupal.
 */
function _bxslider_views_slideshow_add_js($options, $id) {
  // Import variables.
  extract($options);

  $bxslider_path = _bxslider_views_slideshow_library_path();

  // Load Bxslider.
  drupal_add_js($bxslider_path, array('group' => JS_LIBRARY));
  if (!$disable_standard_css) {
    drupal_add_css(libraries_get_path('bxslider') . '/jquery.bxslider.css');
  }

  // Load our Bxslider js.
  drupal_add_js(drupal_get_path('module', 'bxslider_views_slideshow') . '/bxslider_views_slideshow.js');

  // Process Bxslider settings.
  $settings = array(
    'autoStart' => (bool) $autofieldset['autoStart'],
    'mode' => $mode,
    'speed' => (int) $speed,
    'slideMargin' => (int) $slideMargin,
    'startSlide' => (int) $startSlide,
    'randomStart' => (bool) $randomStart,
    'infiniteLoop' => (bool) $infiniteLoop,
    'hideControlsOnEnd' => (bool) $hideControlsOnEnd,
    'captions' => (bool) $captions,
    'pager' => (bool) $pagerfieldset['pager'],
    'pagerType' => $pagerfieldset['pagerType'],
    'controls' => (bool) $controlsfieldset['controls'],
    'auto' => (bool) $autofieldset['auto'],
    'pause' => (int) $autofieldset['pause'],
    'minSlides' => (int) $carousel['minSlides'],
    'maxSlides' => (int) $carousel['maxSlides'],
    'ticker' => (bool) $ticker,
    'tickerHover' => (bool) $tickerHover,
    'adaptiveHeight' => (bool) $adaptiveHeight,
    'adaptiveHeightSpeed' => (int) $adaptiveHeightSpeed,
    'video' => (bool) $video,
    'touchEnabled' => (bool) $touchEnabled,
    'preloadImages' => $preloadImages,
    'swipeThreshold' => (int) $swipeThreshold,
    'oneToOneTouch' => (bool) $oneToOneTouch,
    'preventDefaultSwipeX' => (bool) $preventDefaultSwipeX,
    'preventDefaultSwipeY' => (bool) $preventDefaultSwipeY,
    'pagerShortSeparator' => $pagerfieldset['pagerShortSeparator'],
    'nextText' => $controlsfieldset['nextText'],
    'prevText' => $controlsfieldset['prevText'],
    'startText' => $controlsfieldset['startText'],
    'stopText' => $controlsfieldset['stopText'],
    'autoControls' => (bool) $controlsfieldset['autoControls'],
    'autoControlsCombine' => (bool) $controlsfieldset['autoControlsCombine'],
    'autoHover' => (bool) $autofieldset['autoHover'],
    'autoDelay' => (int) $autofieldset['autoDelay'],
    'moveSlides' => (int) $carousel['moveSlides'],
    'slideWidth' => (int) $carousel['slideWidth'],
  );
  // Load bxslider settings.
  drupal_add_js(array('viewsSlideshowBxslider' => array($id => $settings)), 'setting');
}
