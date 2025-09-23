#ifndef CLIENT_UI_COMPONENTS_STATUSBAR
#define CLIENT_UI_COMPONENTS_STATUSBAR

#include "lvgl.h"

LV_FONT_DECLARE(Montserrat_20r);

class StatusbarPort{
public:
    virtual ~StatusbarPort(){};
    virtual void clickedAtX(uint8_t x) = 0;
};

class Statusbar{
public:
    Statusbar(StatusbarPort* port = nullptr):receiver(port){}

    void create(lv_obj_t* parent){
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

        lv_obj_add_flag(cont, LV_OBJ_FLAG_CLICKABLE);

        timeLabel = lv_label_create(cont);
        lv_label_set_text(timeLabel, "20:00");
        lv_obj_set_style_text_font(timeLabel, &Montserrat_20r, 0);

        batLabel = lv_label_create(cont);
        lv_label_set_text(batLabel, "100%");
        lv_obj_set_style_text_font(batLabel, &Montserrat_20r, 0);

        lv_obj_add_event_cb(cont, event_handler, LV_EVENT_PRESSED, this);
    }
private:
    lv_obj_t* timeLabel;
    lv_obj_t* batLabel;

    StatusbarPort* receiver = nullptr;
private:
    static void event_handler(lv_event_t* e){
        lv_event_code_t code = lv_event_get_code(e);
        Statusbar* obj = (Statusbar*)lv_event_get_user_data(e);

        if(code == LV_EVENT_PRESSED) {
            lv_indev_t * indev = lv_indev_get_act();
            lv_point_t point;
            lv_indev_get_point(indev, &point);
            
            lv_obj_t* cont = (lv_obj_t*)lv_event_get_target(e);
            int32_t x = point.x - lv_obj_get_x(cont);
            obj->_statusBarPressed((x*100/lv_obj_get_width(cont)));
        }
    }

    void _statusBarPressed(uint8_t value){
        if (receiver != nullptr){
            receiver->clickedAtX(value);
        }
    }
};

#endif