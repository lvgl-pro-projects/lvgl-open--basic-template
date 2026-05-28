/**
 * @file list_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "list_gen.h"
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

lv_obj_t * list_create(lv_obj_t * parent, int32_t pad)
{
    LV_TRACE_OBJ_CREATE("begin");

    lv_obj_t * panel_0 = panel_create(parent, pad, 0, LV_FLEX_FLOW_COLUMN, RADIUS, NULL);
    lv_obj_set_name_static(panel_0, "list_#");

    LV_TRACE_OBJ_CREATE("finished");

    return panel_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

