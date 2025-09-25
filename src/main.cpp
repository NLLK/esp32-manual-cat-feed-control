#include "lvgl.h"
#include "app_hal.h"

#include "./client/ui/ui.hpp"
#include "./client/eventHandler/EventHandler.hpp"
#include "./client/adapters/BrightnessControllerStatusbarAdapter.hpp"

Ui* ui;
EventHandler eventHandler;
BrightnessControllerStatusbarAdapter brightnessControllerStatusbarAdapter;

void setup_lvgl(){
    ui = new Ui(&eventHandler);
    ui->init_screen(lv_scr_act());
    ui->setStatusbarAdapter(&brightnessControllerStatusbarAdapter);
    eventHandler.setClientAppearanceInterface(ui);
    
    eventHandler.setTime(CommonDateTime(0,1,1,12,34));
}

#ifdef ARDUINO
#include <Arduino.h>
#include "./tasks/UsbCommandsTask.hpp"
#include "./tasks/GuiUpdateTask.hpp"
#include "RTClib.h"

UsbCommandsTask usbTask;
GuiUpdateTask guiTask;

void setup() {   
    hal_setup();
    setup_lvgl();

    // xSerialMutex = xSemaphoreCreateMutex();
    // xRtcMutex = xSemaphoreCreateMutex();

    // xTaskCreatePinnedToCore(
    //     task_time_update,      // Function name of the task
    //     "Task RTC",   // Name of the task (e.g. for debugging)
    //     4096,        // Stack size (bytes)
    //     (void*)&eventHandler,        // Parameter to pass
    //     2,           // Task priority
    //     NULL,        // Task handle
    //     1            // 
    // );

    guiTask.start();
    usbTask.start();
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