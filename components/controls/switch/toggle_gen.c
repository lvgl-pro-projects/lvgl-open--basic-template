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


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_TEMPLATE_CHECK_COMPILE_TARGET(LVGL_OPEN_TEMPLATE_TARGET_ALL)
    if (lvgl_open_template_check_target(LVGL_OPEN_TEMPLATE_TARGET_ALL)) {
        lv_obj_t * lv_switch_0 = lv_switch_create(parent);
        lv_obj_set_name_static(lv_switch_0, "toggle_#");
        lv_obj_bind_checked(lv_switch_0, subject);
        lv_obj_set_style_bg_color(lv_switch_0, color, LV_PART_INDICATOR | LV_STATE_CHECKED);
        lv_obj_set_style_bg_color(lv_switch_0, COLOR_ACCENT_TEXT, LV_PART_KNOB);

        the_root = lv_switch_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

