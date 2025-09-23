#ifndef CLIENT_UI_UI_H
#define CLIENT_UI_UI_H

#include "lvgl.h"

#include <map>
#include <cstdlib>
#include <functional>

#include "app_hal.h"

#include "./components/MealRow.hpp"
#include "./components/Statusbar.hpp"

struct MealLvObjects{
    lv_obj_t* timeLabel;
    MealType type;
};

LV_FONT_DECLARE(Montserrat_20br);
LV_FONT_DECLARE(Montserrat_20r);
LV_FONT_DECLARE(Montserrat_14r);

class Ui{
public: 
    Ui(){}
    void init_screen(lv_obj_t* parent);

private:


    struct{
        lv_obj_t* timeLabel;
        MealLvObjects meals[4];
    } lvObjects;

private:
    void create_schedule_screen(lv_obj_t * parent);
};

#endif