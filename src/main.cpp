#include "lvgl.h"
#include "app_hal.h"

#include "./client/ui/ui.hpp"
#include "./client/adapters/BrightnessControllerStatusbarAdapter.hpp"

Ui ui;
BrightnessControllerStatusbarAdapter brightnessControllerStatusbarAdapter;

void setup_lvgl(){
    ui.init_screen(lv_scr_act());
    ui.setStatusbarAdapter(&brightnessControllerStatusbarAdapter);
    ui.getStatusbarInterface()->setBatteryLevel(0);
    ui.getStatusbarInterface()->setTimeString("00:00");   
}

#ifdef ARDUINO
#include <Arduino.h>
#include "./tasks/tasks.h"

void setup() {   
    hal_setup();
    setup_lvgl();

    xSerialMutex = xSemaphoreCreateMutex();
    xRtcMutex = xSemaphoreCreateMutex();

	xTaskCreatePinnedToCore(
        task_gui,      // Function name of the task
        "Task gui",   // Name of the task (e.g. for debugging)
        6*1024,        // Stack size (bytes)
        NULL,        // Parameter to pass
        1,           // Task priority
        NULL,        // Task handle
        0            //
    );

    xTaskCreatePinnedToCore(
        task_time_update,      // Function name of the task
        "Task RTC",   // Name of the task (e.g. for debugging)
        4096,        // Stack size (bytes)
        (void*)ui.getStatusbarInterface(),        // Parameter to pass
        2,           // Task priority
        NULL,        // Task handle
        1            // 
    );
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