/**
 * @file list_item_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "list_item_gen.h"
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

lv_obj_t * list_item_create(lv_obj_t * parent, const char * title, const char * subtitle, const void * icon)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_TEMPLATE_CHECK_COMPILE_TARGET(LVGL_OPEN_TEMPLATE_TARGET_ALL)
    if (lvgl_open_template_check_target(LVGL_OPEN_TEMPLATE_TARGET_ALL)) {
        lv_obj_t * container_0 = container_create(parent, SPACE_MD, SPACE_MD, LV_FLEX_FLOW_ROW, 0);
        lv_obj_set_name_static(container_0, "list_item_#");

        lv_obj_add_style(container_0, &style_list_row, 0);
        lv_obj_t * icon_obj = lv_image_create(container_0);
        lv_obj_set_name(icon_obj, "icon_obj");
        lv_image_set_src(icon_obj, icon);
        lv_obj_set_flag(icon_obj, LV_OBJ_FLAG_HIDDEN, !icon);

        lv_obj_t * container_1 = container_create(container_0, 8, SPACE_XS, LV_FLEX_FLOW_COLUMN, 1);
        h5_create(container_1, title);

        lv_obj_t * text_0 = text_create(container_1, subtitle);
        lv_obj_set_flag(text_0, LV_OBJ_FLAG_HIDDEN, !subtitle);
        lv_obj_add_style(text_0, &style_text_muted, 0);

        lv_obj_t * trailing = container_create(container_0, 8, SPACE_SM, LV_FLEX_FLOW_ROW, 0);
        lv_obj_set_name(trailing, "trailing");

        the_root = container_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

lv_obj_t * list_item_get_trailing(lv_obj_t *parent)
{
    return lv_obj_find_by_name(parent, "trailing");
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

