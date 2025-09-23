#include "app_hal.h"
#include <Wire.h>
#include <LVGL_CYD.h>

void hal_setup(void)
{
	LVGL_CYD::begin(USB_DOWN);
	LVGL_CYD::backlight(20);

	lv_tick_set_cb((lv_tick_get_cb_t)millis);

  	Serial.begin(115200);       	
  	Wire1.begin(21, 22);
}

void hal_loop(void)
{
	delay(1000);
}

void hal_setBrighness(uint8_t percents){
    if (percents < 10){
        percents = 10;
    }
	LVGL_CYD::backlight(255*percents/100);
}