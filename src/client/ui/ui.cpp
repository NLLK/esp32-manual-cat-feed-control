#include "ui.h"

#include <cstdlib>

LV_FONT_DECLARE(Montserrat_20br);
LV_FONT_DECLARE(Montserrat_20r);
LV_FONT_DECLARE(Montserrat_14r);
LV_IMAGE_DECLARE(CatImage);

typedef struct {
    lv_obj_t * checkbox;
    lv_obj_t * image;
    bool is_visible;
} checkbox_data_t;

static void checkbox_event_handler(lv_event_t * e) {
    lv_event_code_t code = lv_event_get_code(e);
    checkbox_data_t * data = (checkbox_data_t *)lv_event_get_user_data(e);
    
    if(code == LV_EVENT_CLICKED) {
        data->is_visible = !data->is_visible;
        
        if(data->is_visible) {
            lv_obj_clear_flag(data->image, LV_OBJ_FLAG_HIDDEN);
        } else {
            lv_obj_add_flag(data->image, LV_OBJ_FLAG_HIDDEN);
        }
    }
}

void meal_row_display_create(lv_obj_t* parent, const char* name){

    checkbox_data_t* cb_data = (checkbox_data_t *)malloc(sizeof(checkbox_data_t));

    lv_obj_t * cont = lv_obj_create(parent); 
    lv_obj_set_scroll_dir(cont, LV_DIR_NONE); 
    lv_obj_set_size(cont, 240, 60);
    lv_obj_set_scrollbar_mode(cont, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_style_pad_all(cont, 5, LV_PART_MAIN);
    lv_obj_set_style_border_width(cont, 2, LV_STYLE_STATE_CMP_SAME );
    lv_obj_set_style_border_color(cont, lv_color_hex(0xFFFFFF), LV_STYLE_STATE_CMP_SAME);
    lv_obj_set_style_bg_color(cont, lv_color_hex(0x000000), LV_PART_MAIN);

    lv_obj_t* mealNameLabel = lv_label_create(cont);
    lv_label_set_text(mealNameLabel, name);
    lv_obj_set_style_text_font(mealNameLabel, &Montserrat_20br, 0);
    lv_obj_align(mealNameLabel, LV_ALIGN_LEFT_MID, 0, 0);

    lv_obj_t* timeLabel = lv_label_create(cont);
    lv_label_set_text(timeLabel, "в 07:00");
    lv_obj_set_style_text_font(timeLabel, &Montserrat_14r, 0);
    lv_obj_align(timeLabel, LV_ALIGN_LEFT_MID, 108,0 );

    lv_obj_t* checkbox = lv_obj_create(cont); 
    lv_obj_set_size(checkbox, 50, 50);
    lv_obj_set_style_border_width(checkbox, 4,LV_STYLE_STATE_CMP_SAME );
    lv_obj_align(checkbox, LV_ALIGN_RIGHT_MID, 0, 0);
    lv_obj_set_scroll_dir(checkbox, LV_DIR_NONE); 
    lv_obj_set_scrollbar_mode(checkbox, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_style_pad_all(checkbox, 0, LV_PART_MAIN);
    lv_obj_set_style_bg_color(checkbox, lv_color_hex(0x000000), LV_PART_MAIN);
    lv_obj_set_style_border_color(checkbox, lv_color_hex(0xFFFFFF), LV_STYLE_STATE_CMP_SAME);

    lv_obj_t* catImage = lv_image_create(checkbox);
    lv_image_set_src(catImage, &CatImage);
    lv_obj_align(catImage, LV_ALIGN_CENTER, 0, 0);
    lv_obj_add_flag(catImage, LV_OBJ_FLAG_HIDDEN);

    cb_data->checkbox = checkbox;
    cb_data->image = catImage;
    cb_data->is_visible = false;

    lv_obj_add_event_cb(checkbox, checkbox_event_handler, LV_EVENT_CLICKED, cb_data);
}

void statusbar_create(lv_obj_t* parent){
    lv_obj_t * cont = lv_obj_create(parent); 
    
    lv_obj_set_size(cont, 240, 30);
    lv_obj_set_style_border_side(cont, LV_BORDER_SIDE_BOTTOM, 0);
    lv_obj_set_style_border_width(cont, 2, LV_STYLE_STATE_CMP_SAME);
    lv_obj_set_style_radius(cont, 0,0);
    lv_obj_set_style_border_color(cont, lv_color_hex(0xFFFFFF), LV_STYLE_STATE_CMP_SAME);

    lv_obj_set_scroll_dir(cont, LV_DIR_NONE); 
    lv_obj_set_scrollbar_mode(cont, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_style_pad_all(cont, 0, LV_PART_MAIN);
    lv_obj_set_style_bg_color(cont, lv_color_hex(0x000000), LV_PART_MAIN);

    lv_obj_set_flex_flow(cont, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(cont, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_SPACE_AROUND, LV_FLEX_ALIGN_START);

    lv_obj_t* timeLabel = lv_label_create(cont);
    lv_label_set_text(timeLabel, "20:00");
    lv_obj_set_style_text_font(timeLabel, &Montserrat_20r, 0);

    lv_obj_t* batLabel = lv_label_create(cont);
    lv_label_set_text(batLabel, "100%");
    lv_obj_set_style_text_font(batLabel, &Montserrat_20r, 0);
}

void create_schedule_screen(lv_obj_t * parent) {
    lv_obj_t * cont = lv_obj_create(parent);
    lv_obj_set_scroll_dir(cont, LV_DIR_NONE); 
    lv_obj_set_style_border_width(cont, 0,LV_STYLE_STATE_CMP_SAME );
    lv_obj_set_size(cont, 240, 320);
    lv_obj_align(cont, LV_ALIGN_CENTER, 0, 0);

    lv_obj_set_style_bg_color(cont, lv_color_hex(0x000000), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(cont, 255, LV_PART_MAIN);

    lv_obj_set_flex_flow(cont, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(cont, LV_FLEX_ALIGN_SPACE_AROUND, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);

    lv_obj_set_style_pad_all(cont, 0, LV_PART_MAIN);
    lv_obj_set_scrollbar_mode(cont, LV_SCROLLBAR_MODE_OFF);

    statusbar_create(cont);

    meal_row_display_create(cont, "ЗАВТРАК");
    meal_row_display_create(cont, "ОБЕД");
    meal_row_display_create(cont, "УЖИН");
    meal_row_display_create(cont, "УЖИН 2");
}

void init_screen(lv_obj_t* parent){
    create_schedule_screen(parent);
}