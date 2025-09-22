#include "lvgl.h"
#include "app_hal.h"

#include "./client/ui/ui.h"

#ifdef ARDUINO
#include <Arduino.h>

void setup() {   
    hal_setup();

    lv_obj_t * scr = lv_scr_act();
    init_screen(scr);
}

void loop() {
    hal_loop();
}

#else

int main(void)
{
	lv_init();
	hal_setup();

    lv_obj_t * scr = lv_scr_act();
    init_screen(scr);

    while(1){
        hal_loop();
    } 
}

#endif /*ARDUINO*/