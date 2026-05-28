/**
 * @file screen_home_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "screen_home_gen.h"
#include "../lvgl_open_template.h"

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

static lv_anim_timeline_t * timeline_intro_create(lv_obj_t * obj);
static void free_timeline_event_cb(lv_event_t * e);

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * screen_home_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    static bool style_inited = false;

    if (!style_inited) {

        style_inited = true;
    }

    if (screen_home == NULL) screen_home = lv_obj_create(NULL);
    lv_obj_t * lv_obj_0 = screen_home;
    lv_obj_set_name_static(lv_obj_0, "screen_home_#");

    lv_obj_add_style(lv_obj_0, &style_screen_light, 0);
    lv_obj_bind_style(lv_obj_0, &style_screen_dark, 0, &subject_theme_dark, 1);
    lv_obj_add_style(lv_obj_0, &style_scrollbar, LV_PART_SCROLLBAR);
    lv_obj_t * content = container_create(lv_obj_0, SPACE_LG, SPACE_LG, LV_FLEX_FLOW_COLUMN, NULL);
    lv_obj_set_name(content, "content");
    lv_obj_set_width(content, lv_pct(100));
    lv_obj_set_height(content, lv_pct(100));
    lv_obj_t * container_0 = container_create(content, 0, SPACE_XS, LV_FLEX_FLOW_COLUMN, NULL);
    lv_obj_set_width(container_0, lv_pct(100));
    h1_create(container_0, "LVGL Open");

    lv_obj_t * h5_0 = h5_create(container_0, "XML project template");
    lv_obj_set_style_text_opa(h5_0, (255 * 60 / 100), 0);

    lv_obj_t * container_1 = container_create(content, 0, SPACE_LG, LV_FLEX_FLOW_ROW, 1);
    lv_obj_set_width(container_1, lv_pct(100));
    lv_obj_t * panel_0 = panel_create(container_1, SPACE_MD, SPACE_MD, LV_FLEX_FLOW_COLUMN, RADIUS, 1);
    h4_create(panel_0, "Brightness");

    lv_obj_t * container_2 = container_create(panel_0, 0, SPACE_SM, LV_FLEX_FLOW_COLUMN, NULL);
    lv_obj_set_width(container_2, lv_pct(100));
    lv_obj_set_height(container_2, LV_SIZE_CONTENT);
    lv_obj_set_style_flex_main_place(container_2, LV_FLEX_ALIGN_CENTER, 0);
    lv_obj_set_style_flex_cross_place(container_2, LV_FLEX_ALIGN_CENTER, 0);
    lv_obj_t * arc_0 = arc_create(container_2, &subject_brightness, 0, 100, COLOR_ACCENT);
    lv_obj_t * lv_label_0 = lv_label_create(arc_0);
    lv_label_bind_text(lv_label_0, &subject_brightness, "%d%%");
    lv_obj_set_style_text_font(lv_label_0, font_h2, 0);
    lv_obj_set_align(lv_label_0, LV_ALIGN_CENTER);
    lv_obj_add_style(lv_label_0, &style_text_accent, 0);

    lv_obj_t * panel_1 = panel_create(container_1, SPACE_MD, SPACE_LG, LV_FLEX_FLOW_COLUMN, RADIUS, 1);
    h4_create(panel_1, "Controls");

    lv_obj_t * container_3 = container_create(panel_1, 0, SPACE_XS, LV_FLEX_FLOW_COLUMN, NULL);
    lv_obj_set_width(container_3, lv_pct(100));
    lv_obj_t * h5_1 = h5_create(container_3, "Slider");
    lv_obj_set_style_text_opa(h5_1, (255 * 60 / 100), 0);

    lv_obj_t * slider_0 = slider_create(container_3, &subject_brightness, 0, 100, COLOR_ACCENT);
    lv_obj_set_width(slider_0, lv_pct(100));

    lv_obj_t * container_4 = container_create(panel_1, 0, SPACE_XS, LV_FLEX_FLOW_COLUMN, NULL);
    lv_obj_set_width(container_4, lv_pct(100));
    lv_obj_t * h5_2 = h5_create(container_4, "Bar");
    lv_obj_set_style_text_opa(h5_2, (255 * 60 / 100), 0);

    lv_obj_t * bar_0 = bar_create(container_4, &subject_brightness, 0, 100, COLOR_ACCENT);
    lv_obj_set_width(bar_0, lv_pct(100));

    lv_obj_t * container_5 = container_create(panel_1, 0, 0, LV_FLEX_FLOW_COLUMN, 1);
    lv_obj_set_width(container_5, lv_pct(100));

    lv_obj_t * button_0 = button_create(panel_1, "Settings", COLOR_ACCENT, COLOR_ACCENT_TEXT, RADIUS);
    lv_obj_set_width(button_0, lv_pct(100));
    lv_obj_add_screen_create_event(button_0, LV_EVENT_CLICKED, screen_settings_create, LV_SCREEN_LOAD_ANIM_OVER_LEFT, 350, 0);

    lv_obj_t * button_1 = button_create(panel_1, "Components", COLOR_ACCENT, COLOR_ACCENT_TEXT, RADIUS);
    lv_obj_set_width(button_1, lv_pct(100));
    lv_obj_add_screen_load_event(button_1, LV_EVENT_CLICKED, screen_components, LV_SCREEN_LOAD_ANIM_OVER_LEFT, 350, 0);


    /* create animation timeline(s) */
    lv_anim_timeline_t ** at_array = lv_malloc(sizeof(lv_anim_timeline_t *) * _SCREEN_HOME_TIMELINE_CNT);
    at_array[SCREEN_HOME_TIMELINE_INTRO] = timeline_intro_create(lv_obj_0);
    lv_obj_set_user_data(lv_obj_0, at_array);
    lv_obj_add_event_cb(lv_obj_0, free_timeline_event_cb, LV_EVENT_DELETE, at_array);

    lv_obj_add_play_timeline_event(lv_obj_0, LV_EVENT_SCREEN_LOAD_START, screen_home_get_timeline(lv_obj_0, SCREEN_HOME_TIMELINE_INTRO), 0, false);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

lv_anim_timeline_t * screen_home_get_timeline(lv_obj_t * obj, screen_home_timeline_t timeline_id)
{
    if (timeline_id >= _SCREEN_HOME_TIMELINE_CNT) {
        LV_LOG_WARN("screen_home has no timeline with %d ID", timeline_id);
        return NULL;
    }

    lv_anim_timeline_t ** at_array = lv_obj_get_user_data(obj);
    return at_array[timeline_id];
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/* Helper function to execute animations */
static void int_anim_exec_cb(lv_anim_t * a, int32_t v)
{
    uint32_t data = (lv_uintptr_t)lv_anim_get_user_data(a);
    lv_style_prop_t prop = data >> 24;
    lv_style_selector_t selector = data & 0x00ffffff;

    lv_style_value_t style_value;
    style_value.num = v;
    lv_obj_set_local_style_prop(a->var, prop, style_value, selector);
}

static lv_anim_timeline_t * timeline_intro_create(lv_obj_t * obj)
{
    lv_anim_timeline_t * at = lv_anim_timeline_create();
    lv_anim_timeline_t * at_to_merge = NULL;

    lv_anim_t a;
    uint32_t selector_and_prop;

    selector_and_prop = ((LV_STYLE_TRANSLATE_Y & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "content"));
    lv_anim_set_values(&a, 30, 0);
    lv_anim_set_duration(&a, 400);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 0, &a);

    selector_and_prop = ((LV_STYLE_OPA & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "content"));
    lv_anim_set_values(&a, 0, 255);
    lv_anim_set_duration(&a, 400);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 60, &a);

    return at;
}

static void free_timeline_event_cb(lv_event_t * e)
{
    lv_anim_timeline_t ** at_array = lv_event_get_user_data(e);
    uint32_t i;
    for(i = 0; i < _SCREEN_HOME_TIMELINE_CNT; i++) {
        lv_anim_timeline_delete(at_array[i]);
    }
    lv_free(at_array);
}

