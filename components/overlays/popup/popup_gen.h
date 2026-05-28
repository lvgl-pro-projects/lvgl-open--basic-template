/**
 * @file popup_gen.h
 */

#ifndef POPUP_H
#define POPUP_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
    #include "lvgl_private.h"
#else
    #include "lvgl/lvgl.h"
    #include "lvgl/lvgl_private.h"
#endif

#ifdef LV_USE_XML
    #include "lv_xml/lv_xml.h"
#endif

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

lv_obj_t * popup_create(lv_obj_t * parent, const char * title, bool modal);
lv_obj_t * popup_get_buttons(lv_obj_t *parent);
lv_obj_t * popup_get_content(lv_obj_t *parent);
lv_obj_t * popup_get_footer(lv_obj_t *parent);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*POPUP_H*/