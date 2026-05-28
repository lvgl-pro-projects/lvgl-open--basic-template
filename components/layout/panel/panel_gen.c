/**
 * @file panel_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "panel_gen.h"
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

lv_obj_t * panel_create(lv_obj_t * parent, int32_t pad, int32_t gap, lv_flex_flow_t flow, int32_t radius, int32_t grow)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_panel;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_panel);
        lv_style_set_border_width(&style_panel, BORDER_WIDTH);

        style_inited = true;
    }

    lv_obj_t * container_0 = container_create(parent, pad, gap, flow, grow);
    lv_obj_set_name_static(container_0, "panel_#");
    lv_obj_set_style_radius(container_0, radius, 0);

    lv_obj_add_style(container_0, &style_panel_light, 0);
    lv_obj_bind_style(container_0, &style_panel_dark, 0, &subject_theme_dark, 1);
    lv_obj_add_style(container_0, &style_panel, 0);

    LV_TRACE_OBJ_CREATE("finished");

    return container_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

