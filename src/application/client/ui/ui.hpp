#pragma once

#include <memory>
#include <map>
#include <cstdlib>
#include <functional>

#include "lvgl.h"

#include "../ports/ClientAppearanceInterface.hpp"
#include "../ports/UiMealStateChangedPort.hpp"
#include "../ports/UiBrightnessChangeRequestPort.hpp"

#include "./components/MealRow.hpp"
#include "./components/Statusbar.hpp"

#include "./mappers/StatusBarXToPercentsMapper.hpp"

#include "middleware/logger/Logger.hpp"
#define CLASS_NAME_HEADER std::string("client.Ui: ")

LV_FONT_DECLARE(Montserrat_20br);
LV_FONT_DECLARE(Montserrat_20r);
LV_FONT_DECLARE(Montserrat_14r);

class Ui: public ClientAppearanceInterface, public MealRowPort, public StatusbarPort{
public: 
    Ui(UiMealStateChangedPort* mealStateChangedPort = nullptr, UiBrightnessChangeRequestPort* brightnessChangePort = nullptr)
        :mealStateChangedPort(mealStateChangedPort), brightnessChangePort(brightnessChangePort){
            statusBar.setAdapter(this);
        }

    void init_screen(lv_obj_t* parent){
        create_schedule_screen(parent);
    }

    void setCurrentTime(CommonDateTime time) override {
        LOG.info(CLASS_NAME_HEADER + "setCurrentTime called: %s", time.getDateTimeString().c_str());
        std::string str = time.getTimeString();
        statusBar.setTimeString(str);
    }
    
    void setMealStatus(MealType type, bool status, CommonDateTime time) override {
        LOG.info(CLASS_NAME_HEADER + "setMealStatus called: %s, %d, %s",
            MealTypeStringMapper::map(type).c_str(), status, time.getTimeString().c_str());
             
        getMealRowByType(type)->setStatus(status);
        if (status){
            getMealRowByType(type)->setTimeString(time.getTimeString());
        }else{
            getMealRowByType(type)->setTimeString("");
        }
    }

    void setBatteryPercentage(unsigned short prc){
        LOG.info(CLASS_NAME_HEADER + "setBatteryPercentage called: %d", prc);
        statusBar.setBatteryLevel(prc);
    }

    void statusBarClickedAtX(uint8_t x){
        LOG.info(CLASS_NAME_HEADER + "updateTime called");
        brightnessChangePort->setBrightness(statusBarXToPercentsMapper.map(x));
    }

    void checkboxStateChanged(MealType mealType, bool newState) override{
        LOG.info(CLASS_NAME_HEADER + "updateTime called");
        if (mealStateChangedPort != nullptr){
            mealStateChangedPort->mealStateChanged(mealType, newState);
        }
    }

private:
    MealRow mealBreakfast = MealRow(MealType::BREAKFAST);
    MealRow mealLunch = MealRow(MealType::LUNCH);
    MealRow mealDinner = MealRow(MealType::DINNER);
    MealRow mealDinner2 = MealRow(MealType::DINNER2);

    Statusbar statusBar;
    UiMealStateChangedPort* mealStateChangedPort = nullptr;
    UiBrightnessChangeRequestPort* brightnessChangePort = nullptr;
    StatusBarXToPercentsMapper statusBarXToPercentsMapper;

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

        getMealRowByType(MealType::BREAKFAST)->create(cont);
        getMealRowByType(MealType::LUNCH)->create(cont);
        getMealRowByType(MealType::DINNER)->create(cont);
        getMealRowByType(MealType::DINNER2)->create(cont);

        getMealRowByType(MealType::BREAKFAST)->setReceiver(this);
        getMealRowByType(MealType::LUNCH)->setReceiver(this);
        getMealRowByType(MealType::DINNER)->setReceiver(this);
        getMealRowByType(MealType::DINNER2)->setReceiver(this);
    }

    MealRow* getMealRowByType(MealType type){
        switch (type)
        {
        case MealType::BREAKFAST:
            return &mealBreakfast;
        case MealType::LUNCH:
            return &mealLunch;
        case MealType::DINNER:
            return &mealDinner;
        case MealType::DINNER2:
            return &mealDinner2;
        default:
            return nullptr;
        }
    }    
};