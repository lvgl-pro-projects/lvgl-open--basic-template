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



/* Prototypes for target functions, needed by responsive const definitions */

void lvgl_open_template_set_target(uint32_t target);
uint32_t lvgl_open_template_get_target(void);
bool lvgl_open_template_check_target(uint32_t target);

/*********************
 *      DEFINES
 *********************/

#define LVGL_OPEN_TEMPLATE_TARGET_UNDEFINED  (0 << 1)
#define LVGL_OPEN_TEMPLATE_TARGET_SMALL      (1 << 1)
#define LVGL_OPEN_TEMPLATE_TARGET_MEDIUM     (1 << 2)
#define LVGL_OPEN_TEMPLATE_TARGET_LARGE      (1 << 3)
#define LVGL_OPEN_TEMPLATE_TARGET_ALL        0x0FFFFFFF

/* By default compile for all targets, allowing to switch to any targets at runtime */
#ifndef LVGL_OPEN_TEMPLATE_COMPILE_TARGET
#define LVGL_OPEN_TEMPLATE_COMPILE_TARGET LVGL_OPEN_TEMPLATE_TARGET_ALL
#endif

#define LVGL_OPEN_TEMPLATE_CHECK_COMPILE_TARGET(target) (LVGL_OPEN_TEMPLATE_COMPILE_TARGET & (target) ? 1 : 0)

static inline int32_t space_xs() {
    /**
     * Smallest spacing/padding unit
     */
    if (lvgl_open_template_check_target(LVGL_OPEN_TEMPLATE_TARGET_SMALL)) return 2;
    /**
     * Smallest spacing/padding unit
     */
    if (lvgl_open_template_check_target(LVGL_OPEN_TEMPLATE_TARGET_MEDIUM)) return 4;
    /**
     * Smallest spacing/padding unit
     */
    if (lvgl_open_template_check_target(LVGL_OPEN_TEMPLATE_TARGET_LARGE)) return 6;

    return 0;
}

#define SPACE_XS space_xs()
static inline int32_t space_sm() {
    /**
     * Small spacing/padding unit
     */
    if (lvgl_open_template_check_target(LVGL_OPEN_TEMPLATE_TARGET_SMALL)) return 4;
    /**
     * Small spacing/padding unit
     */
    if (lvgl_open_template_check_target(LVGL_OPEN_TEMPLATE_TARGET_MEDIUM)) return 8;
    /**
     * Small spacing/padding unit
     */
    if (lvgl_open_template_check_target(LVGL_OPEN_TEMPLATE_TARGET_LARGE)) return 12;

    return 0;
}

#define SPACE_SM space_sm()
static inline int32_t space_md() {
    /**
     * Default spacing/padding unit
     */
    if (lvgl_open_template_check_target(LVGL_OPEN_TEMPLATE_TARGET_SMALL)) return 8;
    /**
     * Default spacing/padding unit
     */
    if (lvgl_open_template_check_target(LVGL_OPEN_TEMPLATE_TARGET_MEDIUM)) return 16;
    /**
     * Default spacing/padding unit
     */
    if (lvgl_open_template_check_target(LVGL_OPEN_TEMPLATE_TARGET_LARGE)) return 24;

    return 0;
}

#define SPACE_MD space_md()
static inline int32_t space_lg() {
    /**
     * Large spacing/padding unit
     */
    if (lvgl_open_template_check_target(LVGL_OPEN_TEMPLATE_TARGET_SMALL)) return 12;
    /**
     * Large spacing/padding unit
     */
    if (lvgl_open_template_check_target(LVGL_OPEN_TEMPLATE_TARGET_MEDIUM)) return 24;
    /**
     * Large spacing/padding unit
     */
    if (lvgl_open_template_check_target(LVGL_OPEN_TEMPLATE_TARGET_LARGE)) return 32;

    return 0;
}

#define SPACE_LG space_lg()
static inline int32_t space_xl() {
    /**
     * Extra-large spacing/padding unit
     */
    if (lvgl_open_template_check_target(LVGL_OPEN_TEMPLATE_TARGET_SMALL)) return 20;
    /**
     * Extra-large spacing/padding unit
     */
    if (lvgl_open_template_check_target(LVGL_OPEN_TEMPLATE_TARGET_MEDIUM)) return 40;
    /**
     * Extra-large spacing/padding unit
     */
    if (lvgl_open_template_check_target(LVGL_OPEN_TEMPLATE_TARGET_LARGE)) return 60;

    return 0;
}

#define SPACE_XL space_xl()
static inline int32_t radius() {
    /**
     * Default corner radius
     */
    if (lvgl_open_template_check_target(LVGL_OPEN_TEMPLATE_TARGET_SMALL)) return 8;
    /**
     * Default corner radius
     */
    if (lvgl_open_template_check_target(LVGL_OPEN_TEMPLATE_TARGET_MEDIUM)) return 16;
    /**
     * Default corner radius
     */
    if (lvgl_open_template_check_target(LVGL_OPEN_TEMPLATE_TARGET_LARGE)) return 24;

    return 0;
}

#define RADIUS radius()
static inline int32_t border_width() {
    /**
     * Default border width
     */
    if (lvgl_open_template_check_target(LVGL_OPEN_TEMPLATE_TARGET_SMALL)) return 1;
    /**
     * Default border width
     */
    if (lvgl_open_template_check_target(LVGL_OPEN_TEMPLATE_TARGET_MEDIUM)) return 2;
    /**
     * Default border width
     */
    if (lvgl_open_template_check_target(LVGL_OPEN_TEMPLATE_TARGET_LARGE)) return 3;

    return 0;
}

#define BORDER_WIDTH border_width()
static inline lv_color_t color_accent() {
    /**
     * Accent / active control color
     */
    if (lvgl_open_template_check_target(LVGL_OPEN_TEMPLATE_TARGET_LARGE)) return lv_color_hex(0xd2226c);
    /**
     * Accent / active control color
     */
    if (lvgl_open_template_check_target(LVGL_OPEN_TEMPLATE_TARGET_ALL)) return lv_color_hex(0x9429FF);

    return lv_color_black();
}

#define COLOR_ACCENT color_accent()
/**
 * Default icon size
 */
#define ICON_SIZE 16
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


#ifndef LV_XML_EVAL_STRING_BUF_SIZE
    #define LV_XML_EVAL_STRING_BUF_SIZE 256
#endif

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

/*----------------
 * Global styles
 *----------------*/

extern lv_style_t style_screen_light;
extern lv_style_t style_screen_dark;
extern lv_style_t style_panel_light;
extern lv_style_t style_panel_dark;
extern lv_style_t style_text_accent;
extern lv_style_t style_text_muted;
extern lv_style_t style_list_row;
extern lv_style_t style_track;
extern lv_style_t style_indicator;
extern lv_style_t style_scrollbar;

/*----------------
 * Fonts
 *----------------*/

/* Targets: any */
extern lv_font_t * font_body;
extern lv_font_t * font_h5;
extern lv_font_t * font_h4;
extern lv_font_t * font_h3;
extern lv_font_t * font_h2;
extern lv_font_t * font_h1;


/*----------------
 * Images
 *----------------*/

/* Targets: any */
extern const void * icon_arrow_down;
extern const void * icon_arrow_left;
extern const void * icon_arrow_right;
extern const void * icon_arrow_up;
extern const void * icon_battery;
extern const void * icon_battery_full;
extern const void * icon_bell;
extern const void * icon_bluetooth;
extern const void * icon_calendar;
extern const void * icon_camera;
extern const void * icon_check;
extern const void * icon_chevron_down;
extern const void * icon_chevron_left;
extern const void * icon_chevron_right;
extern const void * icon_chevron_up;
extern const void * icon_clock;
extern const void * icon_close;
extern const void * icon_download;
extern const void * icon_edit;
extern const void * icon_heart;
extern const void * icon_home;
extern const void * icon_info;
extern const void * icon_lock;
extern const void * icon_mail;
extern const void * icon_menu;
extern const void * icon_minus;
extern const void * icon_moon;
extern const void * icon_pause;
extern const void * icon_play;
extern const void * icon_plus;
extern const void * icon_power;
extern const void * icon_refresh;
extern const void * icon_search;
extern const void * icon_settings;
extern const void * icon_signal;
extern const void * icon_star;
extern const void * icon_sun;
extern const void * icon_trash;
extern const void * icon_unlock;
extern const void * icon_upload;
extern const void * icon_user;
extern const void * icon_volume;
extern const void * icon_wifi;
extern const void * icon_wifi_high;
extern const void * icon_wifi_low;
extern const void * icon_wifi_zero;

/*----------------
 * Subjects
 *----------------*/

extern lv_subject_t subject_theme_dark;
extern lv_subject_t subject_brightness;
extern lv_subject_t subject_popup_open;
extern lv_subject_t subject_ringer_volume;
extern lv_subject_t subject_ring_duration;
extern lv_subject_t subject_do_not_disturb;
extern lv_subject_t subject_show_photos;

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

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*LVGL_OPEN_TEMPLATE_GEN_H*/