/**
 * @file screen_settings_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "screen_settings_gen.h"
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

lv_obj_t * screen_settings_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    static bool style_inited = false;

    if (!style_inited) {

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
    lv_obj_set_name_static(lv_obj_0, "screen_settings_#");

    lv_obj_add_style(lv_obj_0, &style_screen_light, 0);
    lv_obj_bind_style(lv_obj_0, &style_screen_dark, 0, &subject_theme_dark, 1);
    lv_obj_add_style(lv_obj_0, &style_scrollbar, LV_PART_SCROLLBAR);
    lv_obj_t * content = container_create(lv_obj_0, SPACE_LG, SPACE_MD, LV_FLEX_FLOW_COLUMN, NULL);
    lv_obj_set_name(content, "content");
    lv_obj_set_width(content, lv_pct(100));
    lv_obj_set_height(content, lv_pct(100));
    h2_create(content, "Settings");

    lv_obj_t * panel_0 = panel_create(content, SPACE_MD, SPACE_SM, LV_FLEX_FLOW_COLUMN, RADIUS, NULL);
    lv_obj_set_width(panel_0, lv_pct(100));
    h4_create(panel_0, "Appearance");

    lv_obj_t * container_0 = container_create(panel_0, 0, SPACE_MD, LV_FLEX_FLOW_ROW, NULL);
    lv_obj_set_width(container_0, lv_pct(100));
    lv_obj_set_style_flex_cross_place(container_0, LV_FLEX_ALIGN_CENTER, 0);
    lv_obj_t * text_0 = text_create(container_0, "Dark mode");
    lv_obj_set_flex_grow(text_0, 1);

    toggle_create(container_0, &subject_theme_dark, COLOR_ACCENT);

    lv_obj_t * panel_1 = panel_create(content, SPACE_MD, SPACE_MD, LV_FLEX_FLOW_COLUMN, RADIUS, NULL);
    lv_obj_set_width(panel_1, lv_pct(100));
    h4_create(panel_1, "Brightness");

    lv_obj_t * slider_0 = slider_create(panel_1, &subject_brightness, 0, 100, COLOR_ACCENT);
    lv_obj_set_width(slider_0, lv_pct(100));

    lv_obj_t * bar_0 = bar_create(panel_1, &subject_brightness, 0, 100, COLOR_ACCENT);
    lv_obj_set_width(bar_0, lv_pct(100));

    lv_obj_t * panel_2 = panel_create(content, SPACE_MD, SPACE_SM, LV_FLEX_FLOW_COLUMN, RADIUS, NULL);
    lv_obj_set_width(panel_2, lv_pct(100));
    h4_create(panel_2, "Notes");

    lv_obj_t * h5_0 = h5_create(panel_2, "Your name");
    lv_obj_set_style_text_opa(h5_0, (255 * 60 / 100), 0);

    lv_obj_t * text_input_0 = text_input_create(panel_2, "", "e.g. Ada Lovelace", false);
    lv_obj_set_width(text_input_0, lv_pct(100));

    lv_obj_t * h5_1 = h5_create(panel_2, "Message");
    lv_obj_set_style_text_opa(h5_1, (255 * 60 / 100), 0);

    lv_obj_t * text_box_0 = text_box_create(panel_2, "", "Write a short note...");
    lv_obj_set_width(text_box_0, lv_pct(100));
    lv_obj_set_height(text_box_0, 100);

    lv_obj_t * button_0 = button_create(content, "Back", COLOR_ACCENT, COLOR_ACCENT_TEXT, RADIUS);
    lv_obj_set_width(button_0, lv_pct(100));
    lv_obj_add_screen_load_event(button_0, LV_EVENT_CLICKED, screen_home, LV_SCREEN_LOAD_ANIM_NONE, 350, 0);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

