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


    static bool style_inited = false;

    if (!style_inited) {

        style_inited = true;
    }

    if (screen_components == NULL) screen_components = lv_obj_create(NULL);
    lv_obj_t * lv_obj_0 = screen_components;
    lv_obj_set_name_static(lv_obj_0, "screen_components_#");

    lv_obj_add_style(lv_obj_0, &style_screen_light, 0);
    lv_obj_bind_style(lv_obj_0, &style_screen_dark, 0, &subject_theme_dark, 1);
    lv_obj_add_style(lv_obj_0, &style_scrollbar, LV_PART_SCROLLBAR);
    lv_obj_t * content = container_create(lv_obj_0, SPACE_LG, SPACE_MD, LV_FLEX_FLOW_COLUMN, NULL);
    lv_obj_set_name(content, "content");
    lv_obj_set_width(content, lv_pct(100));
    lv_obj_set_height(content, lv_pct(100));
    lv_obj_bind_style(content, &style_dim, 0, &subject_popup_open, 1);
    h2_create(content, "Components");

    lv_obj_t * window_0 = window_create(content, "Devices");
    lv_obj_set_width(window_0, lv_pct(100));
    lv_obj_set_flex_grow(window_0, 1);
    lv_obj_t * window_0_buttons = window_get_buttons(window_0);
    if (window_0_buttons) {
    button_create(window_0_buttons, "Add", COLOR_ACCENT, COLOR_ACCENT_TEXT, RADIUS);
    } else {
    LV_LOG_WARN("`buttons` slot of `window_0` doesn't exist");
    }

    lv_obj_t * window_0_content = window_get_content(window_0);
    if (window_0_content) {
    lv_obj_t * list_0 = list_create(window_0_content, 0);
    lv_obj_set_width(list_0, lv_pct(100));
    list_section_create(list_0, "Living room");

    lv_obj_t * list_item_0 = list_item_create(list_0, "Thermostat", "22° • heating");
    lv_obj_t * list_item_0_trailing = list_item_get_trailing(list_item_0);
    if (list_item_0_trailing) {
    lv_obj_t * h5_0 = h5_create(list_item_0_trailing, "On");
    lv_obj_add_style(h5_0, &style_text_accent, 0);
    } else {
    LV_LOG_WARN("`trailing` slot of `list_item_0` doesn't exist");
    }

    lv_obj_t * list_item_1 = list_item_create(list_0, "Brightness", "Display backlight");
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

    list_item_switch_create(list_0, "Dark mode", "Theme for the whole UI", &subject_theme_dark);
    } else {
    LV_LOG_WARN("`content` slot of `window_0` doesn't exist");
    }

    lv_obj_t * button_1 = button_create(content, "Open dialog", COLOR_ACCENT, COLOR_ACCENT_TEXT, RADIUS);
    lv_obj_set_width(button_1, lv_pct(100));
    lv_obj_add_subject_set_int_event(button_1, &subject_popup_open, LV_EVENT_CLICKED, 1);

    lv_obj_t * button_2 = button_create(content, "Back", COLOR_ACCENT, COLOR_ACCENT_TEXT, RADIUS);
    lv_obj_set_width(button_2, lv_pct(100));
    lv_obj_add_screen_load_event(button_2, LV_EVENT_CLICKED, screen_home, LV_SCREEN_LOAD_ANIM_OVER_RIGHT, 350, 0);

    lv_obj_t * popup_0 = popup_create(lv_obj_0, "Delete device?", true);
    lv_obj_bind_flag_if_eq(popup_0, &subject_popup_open, LV_OBJ_FLAG_HIDDEN, 0);
    lv_obj_t * popup_0_content = popup_get_content(popup_0);
    if (popup_0_content) {
    lv_obj_t * text_0 = text_create(popup_0_content, "This removes the device and its automations. This cannot be undone.");
    lv_obj_set_width(text_0, lv_pct(100));
    } else {
    LV_LOG_WARN("`content` slot of `popup_0` doesn't exist");
    }

    lv_obj_t * popup_0_footer = popup_get_footer(popup_0);
    if (popup_0_footer) {
    lv_obj_t * button_3 = button_create(popup_0_footer, "Cancel", COLOR_ACCENT, COLOR_ACCENT_TEXT, RADIUS);
    lv_obj_add_subject_set_int_event(button_3, &subject_popup_open, LV_EVENT_CLICKED, 0);

    lv_obj_t * button_4 = button_create(popup_0_footer, "Delete", COLOR_DANGER, COLOR_ACCENT_TEXT, RADIUS);
    lv_obj_add_subject_set_int_event(button_4, &subject_popup_open, LV_EVENT_CLICKED, 0);
    } else {
    LV_LOG_WARN("`footer` slot of `popup_0` doesn't exist");
    }

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

