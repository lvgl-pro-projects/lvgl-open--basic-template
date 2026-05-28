/**
 * @file button_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "button_gen.h"
#include "../../../lvgl_open_template.h"

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

lv_obj_t * button_create(lv_obj_t * parent, const char * text, lv_color_t bg_color, lv_color_t text_color, int32_t radius)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_button;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_button);
        lv_style_set_pad_hor(&style_button, SPACE_LG);
        lv_style_set_pad_ver(&style_button, SPACE_SM);

        style_inited = true;
    }

    lv_obj_t * lv_button_0 = lv_button_create(parent);
    lv_obj_set_name_static(lv_button_0, "button_#");
    lv_obj_set_style_bg_color(lv_button_0, bg_color, 0);
    lv_obj_set_style_text_color(lv_button_0, text_color, 0);
    lv_obj_set_style_radius(lv_button_0, radius, 0);
    lv_obj_set_style_recolor(lv_button_0, lv_color_hex(0x000000), LV_STATE_PRESSED);
    lv_obj_set_style_recolor_opa(lv_button_0, (255 * 25 / 100), LV_STATE_PRESSED);

    lv_obj_add_style(lv_button_0, &style_button, 0);
    lv_obj_t * lv_label_0 = lv_label_create(lv_button_0);
    lv_obj_set_align(lv_label_0, LV_ALIGN_CENTER);
    lv_label_set_text(lv_label_0, text);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_button_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

