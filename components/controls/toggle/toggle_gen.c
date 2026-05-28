/**
 * @file toggle_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "toggle_gen.h"
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

lv_obj_t * toggle_create(lv_obj_t * parent, lv_subject_t * subject, lv_color_t color)
{
    LV_TRACE_OBJ_CREATE("begin");

    lv_obj_t * lv_switch_0 = lv_switch_create(parent);
    lv_obj_set_name_static(lv_switch_0, "toggle_#");
    lv_obj_bind_checked(lv_switch_0, subject);
    lv_obj_set_style_bg_color(lv_switch_0, color, LV_PART_INDICATOR | LV_PART_KNOB);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_switch_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

