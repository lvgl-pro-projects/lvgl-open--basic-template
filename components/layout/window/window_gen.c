/**
 * @file window_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "window_gen.h"
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

lv_obj_t * window_create(lv_obj_t * parent, const char * title)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_header;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_header);
        lv_style_set_flex_cross_place(&style_header, LV_FLEX_ALIGN_CENTER);
        lv_style_set_border_side(&style_header, LV_BORDER_SIDE_BOTTOM);
        lv_style_set_border_width(&style_header, BORDER_WIDTH);
        lv_style_set_border_color(&style_header, COLOR_TRACK);
        lv_style_set_border_opa(&style_header, (255 * 40 / 100));

        style_inited = true;
    }

    lv_obj_t * panel_0 = panel_create(parent, 0, 0, LV_FLEX_FLOW_COLUMN, RADIUS, NULL);
    lv_obj_set_name_static(panel_0, "window_#");
    lv_obj_set_width(panel_0, lv_pct(100));
    lv_obj_set_height(panel_0, lv_pct(100));

    lv_obj_t * container_0 = container_create(panel_0, SPACE_MD, SPACE_SM, LV_FLEX_FLOW_ROW, NULL);
    lv_obj_set_width(container_0, lv_pct(100));
    lv_obj_add_style(container_0, &style_header, 0);
    lv_obj_t * h4_0 = h4_create(container_0, title);
    lv_obj_set_flex_grow(h4_0, 1);

    lv_obj_t * buttons = container_create(container_0, 0, SPACE_XS, LV_FLEX_FLOW_ROW, NULL);
    lv_obj_set_name(buttons, "buttons");

    lv_obj_t * content = container_create(panel_0, SPACE_MD, SPACE_SM, LV_FLEX_FLOW_COLUMN, 1);
    lv_obj_set_name(content, "content");
    lv_obj_set_width(content, lv_pct(100));

    LV_TRACE_OBJ_CREATE("finished");

    return panel_0;
}

lv_obj_t * window_get_buttons(lv_obj_t *parent)
{
    return lv_obj_find_by_name(parent, "buttons");
}

lv_obj_t * window_get_content(lv_obj_t *parent)
{
    return lv_obj_find_by_name(parent, "content");
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

