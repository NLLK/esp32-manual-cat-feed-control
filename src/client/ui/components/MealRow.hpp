#ifndef CLIENT_UI_COMPONENTS_MEALROW
#define CLIENT_UI_COMPONENTS_MEALROW

#include <map>

#include "lvgl.h"

#include "../../../common/constants/MealType.h"
#include "./CatCheckbox.hpp"

LV_FONT_DECLARE(Montserrat_20br);
LV_FONT_DECLARE(Montserrat_20r);
LV_FONT_DECLARE(Montserrat_14r);

class MealRowPort{
public:
    virtual ~MealRowPort(){};
    virtual void checkboxStateChanged(MealType mealType, bool newState) = 0; 
};

class MealRow: public CatCheckboxPort{
public:

    MealRow(MealType mealType, MealRowPort* port = nullptr): mealType(mealType), receiver(port){}

    void create(lv_obj_t* parent){
        lv_obj_t * cont = lv_obj_create(parent); 
        lv_obj_set_scroll_dir(cont, LV_DIR_NONE); 
        lv_obj_set_size(cont, 240, 60);
        lv_obj_set_scrollbar_mode(cont, LV_SCROLLBAR_MODE_OFF);
        lv_obj_set_style_pad_all(cont, 5, LV_PART_MAIN);
        lv_obj_set_style_border_width(cont, 2, LV_STYLE_STATE_CMP_SAME );
        lv_obj_set_style_border_color(cont, lv_color_hex(0xFFFFFF), LV_STYLE_STATE_CMP_SAME);
        lv_obj_set_style_bg_color(cont, lv_color_hex(0x000000), LV_PART_MAIN);

        lv_obj_t* mealNameLabel = lv_label_create(cont);
        lv_label_set_text(mealNameLabel, mapMealTypeToRussianName.at(mealType));
        lv_obj_set_style_text_font(mealNameLabel, &Montserrat_20br, 0);
        lv_obj_align(mealNameLabel, LV_ALIGN_LEFT_MID, 0, 0);

        timeLabel = lv_label_create(cont);
        setTimeString("00:00");
        lv_obj_set_style_text_font(timeLabel, &Montserrat_14r, 0);
        lv_obj_align(timeLabel, LV_ALIGN_LEFT_MID, 108,0 );

        checkbox = new CatCheckbox(this);
        checkbox->create(cont);
    }

    void setReceiver(MealRowPort* port){
        receiver = port;
    }

    void setStatus(bool status){
        this->status = status;
    }

    void setTimeString(std::string time){
        lv_label_set_text(timeLabel, ("в " + time).c_str());
    }

    void stateChanged(bool newState) override{
        if (receiver != nullptr){
            receiver->checkboxStateChanged(mealType, newState);
        }       
    }

private:
    lv_obj_t* timeLabel;
    MealType mealType;
    CatCheckbox* checkbox = nullptr;

    MealRowPort* receiver = nullptr;
    bool status = false;

    std::map<MealType, const char*> mapMealTypeToRussianName{
        {MealType::BREAKFAST, "ЗАВТРАК"},
        {MealType::LUNCH, "ОБЕД"},
        {MealType::DINNER, "УЖИН"},
        {MealType::DINNER2, "УЖИН 2"}
    };
};  

#endif