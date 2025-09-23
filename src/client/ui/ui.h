#ifndef CLIENT_UI_UI_H
#define CLIENT_UI_UI_H

#include "lvgl.h"

#include <map>
#include <cstdlib>
#include <functional>

#include "app_hal.h"

#include "./components/MealRow.hpp"
#include "./components/Statusbar.hpp"

LV_FONT_DECLARE(Montserrat_20br);
LV_FONT_DECLARE(Montserrat_20r);
LV_FONT_DECLARE(Montserrat_14r);

class Ui{
public: 
    Ui(){}
    void init_screen(lv_obj_t* parent);
    void setStatusbarAdapter(StatusbarPort* adapter){
        statusBar.setAdapter(adapter);
    }

private:
    MealRow mealRows[4] = {
        MealRow(MealType::BREAKFAST), 
        MealRow(MealType::LUNCH),
        MealRow(MealType::DINNER),
        MealRow(MealType::DINNER2)
    };
    Statusbar statusBar;
private:
    void create_schedule_screen(lv_obj_t * parent);
};

#endif