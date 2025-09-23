#ifndef CLIENT_UI_COMPONENTS_CATCHECKBOX
#define CLIENT_UI_COMPONENTS_CATCHECKBOX

#include "lvgl.h"

LV_IMAGE_DECLARE(CatImage);

class CatCheckboxPort{
    virtual ~CatCheckboxPort(){};

};

class CatCheckbox{
public:

    CatCheckbox(){}

    void create(lv_obj_t* parent){
        
        lv_obj_t* checkbox = lv_obj_create(parent); 
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

        // cb_data->checkbox = checkbox;
        // cb_data->image = catImage;
        // cb_data->is_visible = false;

        // lv_obj_add_event_cb(checkbox, checkbox_event_handler, LV_EVENT_CLICKED, cb_data);
    }

    void setStatus(bool status){
        this->status = status;
    }

private:
    lv_obj_t* timeLabel;
    bool status = false;
};  

#endif