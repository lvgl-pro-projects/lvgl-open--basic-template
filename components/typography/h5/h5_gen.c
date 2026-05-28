/**
 * @file h5_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "h5_gen.h"
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

lv_obj_t * h5_create(lv_obj_t * parent, const char * text)
{
    LV_TRACE_OBJ_CREATE("begin");

    lv_obj_t * lv_label_0 = lv_label_create(parent);
    lv_obj_set_name_static(lv_label_0, "h5_#");
    lv_label_set_text(lv_label_0, text);
    lv_obj_set_style_text_font(lv_label_0, font_h5, 0);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_label_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

