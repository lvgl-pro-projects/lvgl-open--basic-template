/**
 * @file slider_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "slider_gen.h"
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

lv_obj_t * slider_create(lv_obj_t * parent, lv_subject_t * subject, int32_t min, int32_t max, lv_color_t color)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_slider_track;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_slider_track);
        lv_style_set_bg_color(&style_slider_track, COLOR_TRACK);
        lv_style_set_bg_opa(&style_slider_track, (255 * 35 / 100));

        style_inited = true;
    }

    lv_obj_t * lv_slider_0 = lv_slider_create(parent);
    lv_obj_set_name_static(lv_slider_0, "slider_#");
    lv_obj_set_width(lv_slider_0, 200);
    lv_slider_set_min_value(lv_slider_0, min);
    lv_slider_set_max_value(lv_slider_0, max);
    lv_slider_bind_value(lv_slider_0, subject);
    lv_obj_set_style_bg_color(lv_slider_0, color, LV_PART_INDICATOR | LV_PART_KNOB);

    lv_obj_add_style(lv_slider_0, &style_slider_track, 0);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_slider_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

