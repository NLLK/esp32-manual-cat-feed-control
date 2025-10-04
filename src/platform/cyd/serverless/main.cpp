#include <LVGL_CYD.h>
#include <Wire.h>
#include "RTClib.h"

#include "application/client/eventHandler/EventHandler.hpp"
#include "application/client/ui/ui.hpp"

#include "../common/adapters/RTCContollerAdapter.hpp"
#include "../common/adapters/BrightnessControllerAdapter.hpp"
#include "./adapters/ServerConnectionProxyAdapter.hpp"

#include "../common/tasks/GuiUpdateTask.hpp"
#include "../common/tasks/RtcTimeUpdateTask.hpp"
#include "../common/tasks/RtcTimeSetTask.hpp"
#include "../common/tasks/ClientUpdateTimeTask.hpp"

#include "./server_setup.hpp"
#include "./fs_setup.hpp"

#include "middleware/logger/Logger.hpp"
#include "../common/adapters/LoggerAdapter.hpp"

Ui* ui;
EventHandler* eventHandler;
RTCContollerAdapter rtc;
BrightnessControllerAdapter brightness;

ServerConnectionProxyAdapter* serverConnectionProxyAdapter;

GuiUpdateTask guiTask;
ClientUpdateTimeTask* clientUpdateTimeTask;
RtcTimeUpdateTask* rtcUpdateTask;
RtcTimeSetTask* rtcSetTask;
SemaphoreHandle_t xRtcMutex;

void setup_application(){
    serverConnectionProxyAdapter = new ServerConnectionProxyAdapter();
    eventHandler = new EventHandler(&brightness, serverConnectionProxyAdapter);

    ui = new Ui(eventHandler, eventHandler);
    ui->init_screen(lv_scr_act());
    eventHandler->setClientAppearanceInterface(ui);
}

void setup_tasks(){
    xRtcMutex = xSemaphoreCreateMutex();

    rtcSetTask = new RtcTimeSetTask(&xRtcMutex);
    rtcUpdateTask = new RtcTimeUpdateTask(serverEventHandler, &xRtcMutex);

    rtc.setTimeSetTask(rtcSetTask);

    clientUpdateTimeTask = new ClientUpdateTimeTask(eventHandler, serverConnectionProxyAdapter);
}

void start_tasks(){
    rtcUpdateTask->start();
    guiTask.start();
    clientUpdateTimeTask->start();
}

void setup(){
    LVGL_CYD::begin(USB_DOWN);
	LVGL_CYD::backlight(20);

	lv_tick_set_cb((lv_tick_get_cb_t)millis);

  	Serial.begin(115200);       	
  	Wire1.begin(21, 22);

    Logger::setLoggerPort(new LoggerAdapter());
    Logger::setLoggingLevel(LoggingLevel::DEBUG);

    setup_application();
    setup_fs();
    setup_server();
    serverConnectionProxyAdapter->setServerEventHandler(serverEventHandler);

    Logger::getInstance().info("Application is ready");

    setup_tasks();
    start_tasks();
}

void loop(){
    delay(1000);
}