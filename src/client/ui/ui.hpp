#ifndef CLIENT_UI_UI_H
#define CLIENT_UI_UI_H

#include "lvgl.h"

#include <map>
#include <cstdlib>
#include <functional>

#include "../ports/ClientAppearanceInterface.hpp"
#include "../ports/UiMealStateChangedPort.hpp"

#include "./components/MealRow.hpp"
#include "./components/Statusbar.hpp"

LV_FONT_DECLARE(Montserrat_20br);
LV_FONT_DECLARE(Montserrat_20r);
LV_FONT_DECLARE(Montserrat_14r);

class Ui: public ClientAppearanceInterface, public MealRowPort{
public: 
    Ui(UiMealStateChangedPort* mealStateChangedPort = nullptr):mealStateChangedPort(mealStateChangedPort){}
    void init_screen(lv_obj_t* parent){
        create_schedule_screen(parent);
    }
    void setStatusbarAdapter(StatusbarPort* adapter){
        statusBar.setAdapter(adapter);
    }
    void setCurrentTime(CommonDateTime time) override {
        std::string str = time.getTimeString();
        statusBar.setTimeString(str);
    }
    void setMealStatus(MealType type, bool status, CommonDateTime time) override {
        mealRowsMap.at(type).setStatus(status);
        mealRowsMap.at(type).setTimeString(time.getTimeString());
    }
    void setBatteryPercentage(unsigned short prc){
        statusBar.setBatteryLevel(prc);
    }

    void checkboxStateChanged(MealType mealType, bool newState) override{
        if (mealStateChangedPort != nullptr){
            mealStateChangedPort->mealStateChanged(mealType, newState);
        }
    }

private:
    std::map<MealType, MealRow> mealRowsMap{
        {MealType::BREAKFAST, MealRow(MealType::BREAKFAST)},
        {MealType::LUNCH, MealRow(MealType::LUNCH)},
        {MealType::DINNER, MealRow(MealType::DINNER)},
        {MealType::DINNER2, MealRow(MealType::DINNER2)}
    };

    Statusbar statusBar;
    UiMealStateChangedPort* mealStateChangedPort = nullptr;
private:
    void create_schedule_screen(lv_obj_t * parent){
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

        statusBar.create(cont);

        for (const auto& [key, value] : mealRowsMap){
            mealRowsMap.at(key).create(cont);
            mealRowsMap.at(key).setReceiver(this);
        }
    }
};

#endif