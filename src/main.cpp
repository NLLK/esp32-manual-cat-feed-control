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
    
    eventHandler.updateTime(CommonDateTime(0,1,1,12,34));
}

#ifdef ARDUINO
#include <Arduino.h>
#include "./tasks/UsbCommandsTask.hpp"
#include "./tasks/GuiUpdateTask.hpp"
#include "./tasks/RtcTimeUpdateTask.hpp"
#include "./tasks/RtcTimeSetTask.hpp"
#include "RTClib.h"

UsbCommandsTask* usbTask;
GuiUpdateTask guiTask;
RtcTimeUpdateTask* rtcUpdateTask;
SemaphoreHandle_t xRtcMutex;

void setup() {   
    hal_setup();
    setup_lvgl();

    xRtcMutex = xSemaphoreCreateMutex();

    rtcTimeSetTaskSingletone = new RtcTimeSetTask(&xRtcMutex);

    rtcUpdateTask = new RtcTimeUpdateTask(&eventHandler, &xRtcMutex);
    rtcUpdateTask->start();
    guiTask.start();

    usbTask = new UsbCommandsTask(&eventHandler);
    usbTask->start();
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