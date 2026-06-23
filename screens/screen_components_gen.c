/**
 * @file screen_components_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "screen_components_gen.h"
#include "../lvgl_open_template.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/***********************
 *  STATIC VARIABLES
 **********************/

/***********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * screen_components_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_TEMPLATE_CHECK_COMPILE_TARGET(LVGL_OPEN_TEMPLATE_TARGET_ALL)
    if (lvgl_open_template_check_target(LVGL_OPEN_TEMPLATE_TARGET_ALL)) {
        if (screen_components == NULL) screen_components = lv_obj_create(NULL);
        lv_obj_t * lv_obj_0 = screen_components;
        lv_obj_set_name_static(lv_obj_0, "screen_components_#");

        lv_obj_add_style(lv_obj_0, &style_screen_light, 0);
        lv_obj_bind_style(lv_obj_0, &style_screen_dark, 0, &subject_theme_dark, 1);
        lv_obj_add_style(lv_obj_0, &style_scrollbar, LV_PART_SCROLLBAR);
        lv_obj_t * content = container_create(lv_obj_0, SPACE_LG, SPACE_MD, LV_FLEX_FLOW_COLUMN, 0);
        lv_obj_set_name(content, "content");
        lv_obj_set_width(content, lv_pct(100));
        lv_obj_set_height(content, lv_pct(100));
        h1_create(content, "Components");

        lv_obj_t * window_0 = window_create(content, "Devices");
        lv_obj_set_width(window_0, lv_pct(100));
        lv_obj_set_height(window_0, lv_pct(100));
        lv_obj_t * window_0_buttons = window_get_buttons(window_0);
        if (window_0_buttons) {
        button_create(window_0_buttons, "Add", icon_plus, COLOR_ACCENT, COLOR_ACCENT_TEXT, RADIUS);
        } else {
        LV_LOG_WARN("`buttons` slot of `window_0` doesn't exist");
        }

        lv_obj_t * window_0_content = window_get_content(window_0);
        if (window_0_content) {
        lv_obj_t * list_0 = list_create(window_0_content, 0, 0);
        lv_obj_set_width(list_0, lv_pct(100));
        list_section_create(list_0, "Living room");

        lv_obj_t * list_item_0 = list_item_create(list_0, "Thermostat", "22° • heating", NULL);
        lv_obj_t * list_item_0_trailing = list_item_get_trailing(list_item_0);
        if (list_item_0_trailing) {
        lv_obj_t * h5_0 = h5_create(list_item_0_trailing, "On");
        lv_obj_add_style(h5_0, &style_text_accent, 0);
        } else {
        LV_LOG_WARN("`trailing` slot of `list_item_0` doesn't exist");
        }

        lv_obj_t * list_item_1 = list_item_create(list_0, "Brightness", "Display backlight", NULL);
        lv_obj_t * list_item_1_trailing = list_item_get_trailing(list_item_1);
        if (list_item_1_trailing) {
        lv_obj_t * lv_label_0 = lv_label_create(list_item_1_trailing);
        lv_label_bind_text(lv_label_0, &subject_brightness, "%d%%");
        lv_obj_add_style(lv_label_0, &style_text_accent, 0);
        } else {
        LV_LOG_WARN("`trailing` slot of `list_item_1` doesn't exist");
        }

        list_separator_create(list_0);

        list_section_create(list_0, "System");
        } else {
        LV_LOG_WARN("`content` slot of `window_0` doesn't exist");
        }

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

