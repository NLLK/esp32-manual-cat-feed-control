#include "lvgl.h"
#include "app_hal.h"

#ifdef ARDUINO
#include <Arduino.h>

void setup() {
  hal_setup();
}

void loop() {
  hal_loop();
}

#else

int main(void)
{
	lv_init();
	hal_setup();

  while(1){
    hal_loop();
  }

}

#endif /*ARDUINO*/