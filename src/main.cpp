#include "lvgl.h"
#include "app_hal.h"

#include "./client/ui/ui.h"

void setup_lvgl(){
    lv_obj_t * scr = lv_scr_act();
    Ui ui;
    ui.init_screen(scr);
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