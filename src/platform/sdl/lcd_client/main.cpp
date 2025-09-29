#include "stdio.h"

#include "lvgl.h"

#include "setup_peripherals.hpp"

#include "../../../application/client/eventHandler/EventHandler.hpp"
#include "../../../application/client/ui/ui.hpp"

#include "./adapters/RTCContollerAdapter.hpp"
#include "./adapters/BrightnessControllerAdapter.hpp"

Ui* ui;
EventHandler* eventHandler;
RTCContollerAdapter rtc;
BrightnessControllerAdapter brightness;

void setup_application(){

    eventHandler = new EventHandler(&rtc, &brightness);

    ui = new Ui(eventHandler, eventHandler);
    ui->init_screen(lv_scr_act());
    eventHandler->setClientAppearanceInterface(ui);
    
    eventHandler->updateTime(CommonDateTime(0,1,1,12,34));
}

void loop(){
    static Uint32 lastTick = SDL_GetTicks();
    SDL_Delay(5);
    Uint32 current = SDL_GetTicks();
    lv_tick_inc(current - lastTick); // Update the tick timer. Tick is new for LVGL 9
    lastTick = current;
    lv_timer_handler(); // Update the UI-
}

int main(void)
{
	lv_init();
    setup_lvgl();

    setup_application();

    while(1){
        loop();
    } 
}

