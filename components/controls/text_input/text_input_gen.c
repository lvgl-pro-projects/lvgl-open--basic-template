/**
 * @file text_input_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "text_input_gen.h"
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

lv_obj_t * text_input_create(lv_obj_t * parent, const char * text, const char * placeholder, bool password)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_TEMPLATE_CHECK_COMPILE_TARGET(LVGL_OPEN_TEMPLATE_TARGET_ALL)
    if (lvgl_open_template_check_target(LVGL_OPEN_TEMPLATE_TARGET_ALL)) {
        lv_obj_t * lv_textarea_0 = lv_textarea_create(parent);
        lv_obj_set_name_static(lv_textarea_0, "text_input_#");
        lv_textarea_set_one_line(lv_textarea_0, true);
        lv_obj_set_width(lv_textarea_0, 260);
        lv_textarea_set_text(lv_textarea_0, text);
        lv_textarea_set_placeholder_text(lv_textarea_0, placeholder);
        lv_textarea_set_password_mode(lv_textarea_0, password);
        lv_obj_set_style_radius(lv_textarea_0, RADIUS, 0);

        the_root = lv_textarea_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

