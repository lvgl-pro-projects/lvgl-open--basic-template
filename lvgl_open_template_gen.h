/**
 * @file lvgl_open_template_gen.h
 */

#ifndef LVGL_OPEN_TEMPLATE_GEN_H
#define LVGL_OPEN_TEMPLATE_GEN_H

#ifndef UI_SUBJECT_STRING_LENGTH
#define UI_SUBJECT_STRING_LENGTH 256
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
    #include "lvgl_private.h"
#else
    #include "lvgl/lvgl.h"
    #include "lvgl/lvgl_private.h"
#endif

#ifdef LV_USE_XML
    #include "lv_xml/lv_xml.h"
#endif



/*********************
 *      DEFINES
 *********************/

/**
 * Smallest spacing/padding unit
 */
#define SPACE_XS 4

/**
 * Small spacing/padding unit
 */
#define SPACE_SM 8

/**
 * Default spacing/padding unit
 */
#define SPACE_MD 16

/**
 * Large spacing/padding unit
 */
#define SPACE_LG 24

/**
 * Extra-large spacing/padding unit
 */
#define SPACE_XL 40

/**
 * Default corner radius
 */
#define RADIUS 14

/**
 * Default border width
 */
#define BORDER_WIDTH 2

/**
 * Light theme screen background
 */
#define COLOR_LIGHT_BG lv_color_hex(0xEEF1F6)

/**
 * Light theme panel/card background
 */
#define COLOR_LIGHT_PANEL lv_color_hex(0xFFFFFF)

/**
 * Light theme primary text
 */
#define COLOR_LIGHT_TEXT lv_color_hex(0x1B1F27)

/**
 * Dark theme screen background
 */
#define COLOR_DARK_BG lv_color_hex(0x12151C)

/**
 * Dark theme panel/card background
 */
#define COLOR_DARK_PANEL lv_color_hex(0x1E232E)

/**
 * Dark theme primary text
 */
#define COLOR_DARK_TEXT lv_color_hex(0xE6E9F0)

/**
 * Accent / active control color
 */
#define COLOR_ACCENT lv_color_hex(0x9429FF)

/**
 * Text/icon drawn on top of the accent color
 */
#define COLOR_ACCENT_TEXT lv_color_hex(0xFFFFFF)

/**
 * Destructive / warning color
 */
#define COLOR_DANGER lv_color_hex(0xE5484D)

/**
 * Neutral track behind sliders/arcs/bars
 */
#define COLOR_TRACK lv_color_hex(0x9AA3B2)

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL VARIABLES
 **********************/

/*-------------------
 * Permanent screens
 *------------------*/

extern lv_obj_t * screen_components;
extern lv_obj_t * screen_home;

/*----------------
 * Global styles
 *----------------*/

extern lv_style_t style_screen_light;
extern lv_style_t style_screen_dark;
extern lv_style_t style_panel_light;
extern lv_style_t style_panel_dark;
extern lv_style_t style_text_accent;
extern lv_style_t style_muted;
extern lv_style_t style_list_row;
extern lv_style_t style_dim;
extern lv_style_t style_track;
extern lv_style_t style_indicator;
extern lv_style_t style_scrollbar;

/*----------------
 * Fonts
 *----------------*/

extern lv_font_t * font_body;

extern lv_font_t * font_h5;

extern lv_font_t * font_h4;

extern lv_font_t * font_h3;

extern lv_font_t * font_h2;

extern lv_font_t * font_h1;

/*----------------
 * Images
 *----------------*/

/*----------------
 * Subjects
 *----------------*/

extern lv_subject_t subject_theme_dark;
extern lv_subject_t subject_brightness;
extern lv_subject_t subject_popup_open;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/*----------------
 * Event Callbacks
 *----------------*/

/**
 * Initialize the component library
 */

void lvgl_open_template_init_gen(const char * asset_path);

/**********************
 *      MACROS
 **********************/

/**********************
 *   POST INCLUDES
 **********************/

/*Include all the widgets, components and screens of this library*/
#include "components/controls/arc/arc_gen.h"
#include "components/controls/bar/bar_gen.h"
#include "components/controls/button/button_gen.h"
#include "components/controls/slider/slider_gen.h"
#include "components/controls/text_box/text_box_gen.h"
#include "components/controls/text_input/text_input_gen.h"
#include "components/controls/toggle/toggle_gen.h"
#include "components/layout/base_box/base_box_gen.h"
#include "components/layout/container/container_gen.h"
#include "components/layout/panel/panel_gen.h"
#include "components/layout/window/window_gen.h"
#include "components/list/list_item_switch/list_item_switch_gen.h"
#include "components/list/list_item/list_item_gen.h"
#include "components/list/list_section/list_section_gen.h"
#include "components/list/list_separator/list_separator_gen.h"
#include "components/list/list/list_gen.h"
#include "components/overlays/popup/popup_gen.h"
#include "components/typography/h1/h1_gen.h"
#include "components/typography/h2/h2_gen.h"
#include "components/typography/h3/h3_gen.h"
#include "components/typography/h4/h4_gen.h"
#include "components/typography/h5/h5_gen.h"
#include "components/typography/text/text_gen.h"
#include "screens/screen_components_gen.h"
#include "screens/screen_home_gen.h"
#include "screens/screen_settings_gen.h"

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*LVGL_OPEN_TEMPLATE_GEN_H*/