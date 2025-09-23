#include "ui.h"

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

void Ui::create_schedule_screen(lv_obj_t * parent) {
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

    Statusbar statusBar;
    statusBar.create(cont);

    for (int i = 0; i < 4; i++){
        mealRows[i].create(cont);
    }
}

void Ui::init_screen(lv_obj_t* parent){
    create_schedule_screen(parent);
}