#include "lvgl.h"
#include "app_hal.h"

#include "./client/ui/ui.hpp"
#include "./client/adapters/BrightnessControllerStatusbarAdapter.hpp"

Ui ui;
BrightnessControllerStatusbarAdapter brightnessControllerStatusbarAdapter;

void setup_lvgl(){
    ui.init_screen(lv_scr_act());
    ui.setStatusbarAdapter(&brightnessControllerStatusbarAdapter);
}

#ifdef ARDUINO
#include <Arduino.h>

void setup() {   
    hal_setup();

    setup_lvgl();
}

void loop() {
    hal_loop();
}

#else

int main(void)
{
	lv_init();
	hal_setup();

    setup_lvgl();

    while(1){
        hal_loop();
    } 
}

#endif /*ARDUINO*/