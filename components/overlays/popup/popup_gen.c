/**
 * @file popup_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "popup_gen.h"
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

lv_obj_t * popup_create(lv_obj_t * parent, const char * title, bool modal)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_dialog;
    static lv_style_t style_header;
    static lv_style_t style_footer;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_dialog);
        lv_style_set_width(&style_dialog, lv_pct(60));
        lv_style_set_max_height(&style_dialog, lv_pct(90));

        lv_style_init(&style_header);
        lv_style_set_flex_cross_place(&style_header, LV_FLEX_ALIGN_CENTER);
        lv_style_set_border_side(&style_header, LV_BORDER_SIDE_BOTTOM);
        lv_style_set_border_width(&style_header, BORDER_WIDTH);
        lv_style_set_border_color(&style_header, COLOR_TRACK);
        lv_style_set_border_opa(&style_header, (255 * 40 / 100));

        lv_style_init(&style_footer);
        lv_style_set_flex_main_place(&style_footer, LV_FLEX_ALIGN_END);
        lv_style_set_flex_cross_place(&style_footer, LV_FLEX_ALIGN_CENTER);
        lv_style_set_border_side(&style_footer, LV_BORDER_SIDE_TOP);
        lv_style_set_border_width(&style_footer, BORDER_WIDTH);
        lv_style_set_border_color(&style_footer, COLOR_TRACK);
        lv_style_set_border_opa(&style_footer, (255 * 40 / 100));

        style_inited = true;
    }

    lv_obj_t * base_box_0 = base_box_create(parent);
    lv_obj_set_name_static(base_box_0, "popup_#");
    lv_obj_set_width(base_box_0, lv_pct(100));
    lv_obj_set_height(base_box_0, lv_pct(100));
    lv_obj_set_flag(base_box_0, LV_OBJ_FLAG_FLOATING, true);
    lv_obj_set_flag(base_box_0, LV_OBJ_FLAG_CLICKABLE, modal);
    lv_obj_set_style_flex_main_place(base_box_0, LV_FLEX_ALIGN_CENTER, 0);
    lv_obj_set_style_flex_cross_place(base_box_0, LV_FLEX_ALIGN_CENTER, 0);

    lv_obj_t * panel_0 = panel_create(base_box_0, 0, 0, LV_FLEX_FLOW_COLUMN, RADIUS, NULL);
    lv_obj_add_style(panel_0, &style_dialog, 0);
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

    lv_obj_t * container_1 = container_create(panel_0, SPACE_MD, SPACE_SM, LV_FLEX_FLOW_ROW, NULL);
    lv_obj_set_width(container_1, lv_pct(100));
    lv_obj_add_style(container_1, &style_footer, 0);
    lv_obj_t * footer = container_create(container_1, 0, SPACE_SM, LV_FLEX_FLOW_ROW, NULL);
    lv_obj_set_name(footer, "footer");

    LV_TRACE_OBJ_CREATE("finished");

    return base_box_0;
}

lv_obj_t * popup_get_buttons(lv_obj_t *parent)
{
    return lv_obj_find_by_name(parent, "buttons");
}

lv_obj_t * popup_get_content(lv_obj_t *parent)
{
    return lv_obj_find_by_name(parent, "content");
}

lv_obj_t * popup_get_footer(lv_obj_t *parent)
{
    return lv_obj_find_by_name(parent, "footer");
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

