/**
 * @file list_separator_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "list_separator_gen.h"
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

lv_obj_t * list_separator_create(lv_obj_t * parent)
{
    LV_TRACE_OBJ_CREATE("begin");

    lv_obj_t * container_0 = container_create(parent, 0, 0, LV_FLEX_FLOW_COLUMN, NULL);
    lv_obj_set_name_static(container_0, "list_separator_#");
    lv_obj_set_width(container_0, lv_pct(100));
    lv_obj_set_height(container_0, 1);
    lv_obj_set_style_bg_color(container_0, COLOR_TRACK, 0);
    lv_obj_set_style_bg_opa(container_0, (255 * 25 / 100), 0);

    LV_TRACE_OBJ_CREATE("finished");

    return container_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

