/**
 * @file list_item_switch_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "list_item_switch_gen.h"
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

lv_obj_t * list_item_switch_create(lv_obj_t * parent, const char * title, const char * subtitle, lv_subject_t * subject)
{
    LV_TRACE_OBJ_CREATE("begin");

    lv_obj_t * container_0 = container_create(parent, SPACE_MD, SPACE_MD, LV_FLEX_FLOW_ROW, NULL);
    lv_obj_set_name_static(container_0, "list_item_switch_#");

    lv_obj_add_style(container_0, &style_list_row, 0);
    lv_obj_t * container_1 = container_create(container_0, 0, 2, LV_FLEX_FLOW_COLUMN, 1);
    h5_create(container_1, title);

    lv_obj_t * text_0 = text_create(container_1, subtitle);
    lv_obj_add_style(text_0, &style_muted, 0);

    toggle_create(container_0, subject, COLOR_ACCENT);

    LV_TRACE_OBJ_CREATE("finished");

    return container_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

