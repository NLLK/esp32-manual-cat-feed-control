#include <LVGL_CYD.h>
#include <Wire.h>
#include "RTClib.h"

#include "../../../application/client/eventHandler/EventHandler.hpp"
#include "../../../application/client/ui/ui.hpp"

#include "./adapters/RTCContollerAdapter.hpp"
#include "./adapters/BrightnessControllerAdapter.hpp"

#include "./tasks/UsbCommandsTask.hpp"
#include "./tasks/GuiUpdateTask.hpp"
#include "./tasks/RtcTimeUpdateTask.hpp"
#include "./tasks/RtcTimeSetTask.hpp"

Ui* ui;
EventHandler* eventHandler;
RTCContollerAdapter rtc;
BrightnessControllerAdapter brightness;

UsbCommandsTask* usbTask;
GuiUpdateTask guiTask;
RtcTimeUpdateTask* rtcUpdateTask;
RtcTimeSetTask* rtcSetTask;
SemaphoreHandle_t xRtcMutex;

void setup_application(){
    eventHandler = new EventHandler(&rtc, &brightness);

    ui = new Ui(eventHandler, eventHandler);
    ui->init_screen(lv_scr_act());
    eventHandler->setClientAppearanceInterface(ui);
    
    eventHandler->updateTime(CommonDateTime(0,1,1,12,34));
}

void setup_tasks(){

    xRtcMutex = xSemaphoreCreateMutex();

    rtcSetTask = new RtcTimeSetTask(&xRtcMutex);
    rtcUpdateTask = new RtcTimeUpdateTask(eventHandler, &xRtcMutex);
    usbTask = new UsbCommandsTask(eventHandler); 
}

void start_tasks(){
    rtcUpdateTask->start();
    guiTask.start();
    usbTask->start();
}

void post_task_setup(){
    rtc.setTimeSetTask(rtcSetTask);
}

void setup(){
    LVGL_CYD::begin(USB_DOWN);
	LVGL_CYD::backlight(20);

	lv_tick_set_cb((lv_tick_get_cb_t)millis);

  	Serial.begin(115200);       	
  	Wire1.begin(21, 22);

    setup_application();
    setup_tasks();

    post_task_setup();

    start_tasks();
}

void loop(){
    delay(1000);
}