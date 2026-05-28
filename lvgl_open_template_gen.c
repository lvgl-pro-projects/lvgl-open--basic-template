/**
 * @file lvgl_open_template_gen.c
 */

/*********************
 *      INCLUDES
 *********************/

#include "lvgl_open_template_gen.h"

#if LV_USE_XML
#endif /* LV_USE_XML */

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/*----------------
 * Translations
 *----------------*/

/**********************
 *  GLOBAL VARIABLES
 **********************/

/*--------------------
 *  Permanent screens
 *-------------------*/

lv_obj_t * screen_components = NULL;
lv_obj_t * screen_home = NULL;

/*----------------
 * Fonts
 *----------------*/

lv_font_t * font_body;
extern lv_font_t font_body_data;
lv_font_t * font_h5;
extern lv_font_t font_h5_data;
lv_font_t * font_h4;
extern lv_font_t font_h4_data;
lv_font_t * font_h3;
extern lv_font_t font_h3_data;
lv_font_t * font_h2;
extern lv_font_t font_h2_data;
lv_font_t * font_h1;
extern lv_font_t font_h1_data;

/*----------------
 * Images
 *----------------*/

/*----------------
 * Global styles
 *----------------*/

lv_style_t style_screen_light;
lv_style_t style_screen_dark;
lv_style_t style_panel_light;
lv_style_t style_panel_dark;
lv_style_t style_text_accent;
lv_style_t style_muted;
lv_style_t style_list_row;
lv_style_t style_dim;
lv_style_t style_track;
lv_style_t style_indicator;
lv_style_t style_scrollbar;

/*----------------
 * Subjects
 *----------------*/

lv_subject_t subject_theme_dark;
lv_subject_t subject_brightness;
lv_subject_t subject_popup_open;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lvgl_open_template_init_gen(const char * asset_path)
{
    char buf[256];


    /*----------------
     * Fonts
     *----------------*/

    /* get font 'font_body' from a C array */
    font_body = &font_body_data;
    /* get font 'font_h5' from a C array */
    font_h5 = &font_h5_data;
    /* get font 'font_h4' from a C array */
    font_h4 = &font_h4_data;
    /* get font 'font_h3' from a C array */
    font_h3 = &font_h3_data;
    /* get font 'font_h2' from a C array */
    font_h2 = &font_h2_data;
    /* get font 'font_h1' from a C array */
    font_h1 = &font_h1_data;


    /*----------------
     * Images
     *----------------*/
    /*----------------
     * Global styles
     *----------------*/

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_screen_light);
        lv_style_set_bg_color(&style_screen_light, COLOR_LIGHT_BG);
        lv_style_set_bg_opa(&style_screen_light, (255 * 100 / 100));
        lv_style_set_text_color(&style_screen_light, COLOR_LIGHT_TEXT);
        lv_style_set_text_font(&style_screen_light, font_body);

        lv_style_init(&style_screen_dark);
        lv_style_set_bg_color(&style_screen_dark, COLOR_DARK_BG);
        lv_style_set_bg_opa(&style_screen_dark, (255 * 100 / 100));
        lv_style_set_text_color(&style_screen_dark, COLOR_DARK_TEXT);
        lv_style_set_text_font(&style_screen_dark, font_body);

        lv_style_init(&style_panel_light);
        lv_style_set_bg_color(&style_panel_light, COLOR_LIGHT_PANEL);
        lv_style_set_bg_opa(&style_panel_light, (255 * 100 / 100));
        lv_style_set_border_color(&style_panel_light, COLOR_LIGHT_TEXT);
        lv_style_set_border_opa(&style_panel_light, (255 * 12 / 100));
        lv_style_set_border_width(&style_panel_light, BORDER_WIDTH);

        lv_style_init(&style_panel_dark);
        lv_style_set_bg_color(&style_panel_dark, COLOR_DARK_PANEL);
        lv_style_set_bg_opa(&style_panel_dark, (255 * 100 / 100));
        lv_style_set_border_color(&style_panel_dark, COLOR_DARK_TEXT);
        lv_style_set_border_opa(&style_panel_dark, (255 * 12 / 100));
        lv_style_set_border_width(&style_panel_dark, BORDER_WIDTH);

        lv_style_init(&style_text_accent);
        lv_style_set_text_color(&style_text_accent, COLOR_ACCENT);

        lv_style_init(&style_muted);
        lv_style_set_text_opa(&style_muted, (255 * 60 / 100));

        lv_style_init(&style_list_row);
        lv_style_set_width(&style_list_row, lv_pct(100));
        lv_style_set_flex_cross_place(&style_list_row, LV_FLEX_ALIGN_CENTER);
        lv_style_set_border_side(&style_list_row, LV_BORDER_SIDE_BOTTOM);
        lv_style_set_border_width(&style_list_row, 1);
        lv_style_set_border_color(&style_list_row, COLOR_TRACK);
        lv_style_set_border_opa(&style_list_row, (255 * 25 / 100));

        lv_style_init(&style_dim);
        lv_style_set_recolor(&style_dim, lv_color_hex(0x000000));
        lv_style_set_recolor_opa(&style_dim, (255 * 45 / 100));

        lv_style_init(&style_track);
        lv_style_set_bg_color(&style_track, COLOR_TRACK);
        lv_style_set_bg_opa(&style_track, (255 * 35 / 100));
        lv_style_set_arc_color(&style_track, COLOR_TRACK);
        lv_style_set_arc_opa(&style_track, (255 * 35 / 100));

        lv_style_init(&style_indicator);
        lv_style_set_bg_color(&style_indicator, COLOR_ACCENT);
        lv_style_set_arc_color(&style_indicator, COLOR_ACCENT);

        lv_style_init(&style_scrollbar);
        lv_style_set_width(&style_scrollbar, SPACE_XS);
        lv_style_set_radius(&style_scrollbar, SPACE_XS);
        lv_style_set_bg_color(&style_scrollbar, COLOR_TRACK);
        lv_style_set_bg_opa(&style_scrollbar, (255 * 80 / 100));

        style_inited = true;
    }

    /*----------------
     * Subjects
     *----------------*/
    lv_subject_init_int(&subject_theme_dark, 0);
    lv_subject_set_min_value_int(&subject_theme_dark, 0);
    lv_subject_set_max_value_int(&subject_theme_dark, 1);
    lv_subject_init_int(&subject_brightness, 60);
    lv_subject_set_min_value_int(&subject_brightness, 0);
    lv_subject_set_max_value_int(&subject_brightness, 100);
    lv_subject_init_int(&subject_popup_open, 0);
    lv_subject_set_min_value_int(&subject_popup_open, 0);
    lv_subject_set_max_value_int(&subject_popup_open, 1);

    /*----------------
     * Translations
     *----------------*/

#if LV_USE_XML
    /* Register widgets */

    /* Register fonts */
    lv_xml_register_font(NULL, "font_body", font_body);
    lv_xml_register_font(NULL, "font_h5", font_h5);
    lv_xml_register_font(NULL, "font_h4", font_h4);
    lv_xml_register_font(NULL, "font_h3", font_h3);
    lv_xml_register_font(NULL, "font_h2", font_h2);
    lv_xml_register_font(NULL, "font_h1", font_h1);

    /* Register subjects */
    lv_xml_register_subject(NULL, "subject_theme_dark", &subject_theme_dark);
    lv_xml_register_subject(NULL, "subject_brightness", &subject_brightness);
    lv_xml_register_subject(NULL, "subject_popup_open", &subject_popup_open);

    /* Register callbacks */
#endif

    /* Register all the global assets so that they won't be created again when globals.xml is parsed.
     * While running in the editor skip this step to update the preview when the XML changes */
#if LV_USE_XML && !defined(LV_EDITOR_PREVIEW)
    /* Register images */
#endif

#if LV_USE_XML == 0
    /*--------------------
     *  Permanent screens
     *-------------------*/
    /* If XML is enabled it's assumed that the permanent screens are created
     * manaully from XML using lv_xml_create() */
    /* To allow screens to reference each other, create them all before calling the sceen create functions */
    screen_components = lv_obj_create(NULL);
    screen_home = lv_obj_create(NULL);

    screen_components_create();
    screen_home_create();
#endif
}

/* Callbacks */

/**********************
 *   STATIC FUNCTIONS
 **********************/