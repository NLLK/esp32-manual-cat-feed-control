#include "app_hal.h"

#include <LVGL_CYD.h>
#include "./tasks/tasks.h"

void hal_setup(void)
{
	LVGL_CYD::begin(USB_DOWN);
	LVGL_CYD::backlight(20);

	lv_tick_set_cb((lv_tick_get_cb_t)millis);

  	Serial.begin(115200);       	
  	Wire1.begin(21, 22);

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
        NULL,        // Parameter to pass
        2,           // Task priority
        NULL,        // Task handle
        1            // 
    );
}

void hal_loop(void)
{
	delay(1000);
}

void hal_setBrighness(uint8_t percents){
	LVGL_CYD::backlight(255*percents/100);
}