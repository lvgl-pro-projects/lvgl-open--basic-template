/**
 * @file base_box_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "base_box_gen.h"
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

lv_obj_t * base_box_create(lv_obj_t * parent)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_base_box;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_base_box);
        lv_style_set_width(&style_base_box, LV_SIZE_CONTENT);
        lv_style_set_height(&style_base_box, LV_SIZE_CONTENT);
        lv_style_set_bg_opa(&style_base_box, (255 * 0 / 100));
        lv_style_set_border_width(&style_base_box, 0);
        lv_style_set_pad_all(&style_base_box, 0);
        lv_style_set_layout(&style_base_box, LV_LAYOUT_FLEX);

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(parent);
    lv_obj_set_name_static(lv_obj_0, "base_box_#");

    lv_obj_remove_style_all(lv_obj_0);
    lv_obj_add_style(lv_obj_0, &style_base_box, 0);
    lv_obj_add_style(lv_obj_0, &style_scrollbar, LV_PART_SCROLLBAR);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

