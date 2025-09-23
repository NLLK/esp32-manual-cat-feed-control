#ifndef CLIENT_UI_COMPONENTS_CATCHECKBOX
#define CLIENT_UI_COMPONENTS_CATCHECKBOX

#include "lvgl.h"

LV_IMAGE_DECLARE(CatImage);

class CatCheckboxPort{
public:
    virtual ~CatCheckboxPort(){};
    virtual void stateChanged(bool newState) = 0;
};

class CatCheckbox{
public:

    CatCheckbox(CatCheckboxPort* port = nullptr):receiver(port){}

    void create(lv_obj_t* parent){
        
        checkboxObj = lv_obj_create(parent); 
        lv_obj_set_size(checkboxObj, 50, 50);
        lv_obj_set_style_border_width(checkboxObj, 4,LV_STYLE_STATE_CMP_SAME );
        lv_obj_align(checkboxObj, LV_ALIGN_RIGHT_MID, 0, 0);
        lv_obj_set_scroll_dir(checkboxObj, LV_DIR_NONE); 
        lv_obj_set_scrollbar_mode(checkboxObj, LV_SCROLLBAR_MODE_OFF);
        lv_obj_set_style_pad_all(checkboxObj, 0, LV_PART_MAIN);
        lv_obj_set_style_bg_color(checkboxObj, lv_color_hex(0x000000), LV_PART_MAIN);
        lv_obj_set_style_border_color(checkboxObj, lv_color_hex(0xFFFFFF), LV_STYLE_STATE_CMP_SAME);

        catImage = lv_image_create(checkboxObj);
        lv_image_set_src(catImage, &CatImage);
        lv_obj_align(catImage, LV_ALIGN_CENTER, 0, 0);
        lv_obj_add_flag(catImage, LV_OBJ_FLAG_HIDDEN);

        lv_obj_add_event_cb(checkboxObj, event_handler, LV_EVENT_CLICKED, this);
    }

    void setStatus(bool status){
        this->status = status;

        if (status){
            lv_obj_clear_flag(catImage, LV_OBJ_FLAG_HIDDEN);
        }else{
            lv_obj_add_flag(catImage, LV_OBJ_FLAG_HIDDEN); 
        }
    }


private:
    lv_obj_t* catImage = nullptr;
    lv_obj_t* checkboxObj = nullptr;
    bool status = false;

    CatCheckboxPort* receiver = nullptr; 

private:
    static void event_handler(lv_event_t* e){
        lv_event_code_t code = lv_event_get_code(e);
        CatCheckbox* obj = (CatCheckbox*)lv_event_get_user_data(e);

        if(code == LV_EVENT_CLICKED && obj) {
            obj->_stateChanged();
        }
    }

    void _stateChanged(){
        setStatus(!status);

        if (receiver != nullptr){
            receiver->stateChanged(status);
        }
    }
};  

#endif