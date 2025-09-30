#include "stdio.h"

#include "lvgl.h"

#include "setup_peripherals.hpp"

#include "../../../application/client/eventHandler/EventHandler.hpp"
#include "../../../application/client/ui/ui.hpp"

#include "./adapters/RTCContollerAdapter.hpp"
#include "./adapters/BrightnessControllerAdapter.hpp"
#include "./adapters/ServerConnectionProxyAdapter.hpp"

#include "./server_setup.hpp"

Ui* ui;
EventHandler* eventHandler;
BrightnessControllerAdapter brightness;
ServerConnectionProxyAdapter* serverConnectionProxyAdapter;

void setup_application(){
    serverConnectionProxyAdapter = new ServerConnectionProxyAdapter();
    eventHandler = new EventHandler(&brightness);

    ui = new Ui(eventHandler, eventHandler);
    ui->init_screen(lv_scr_act());
    eventHandler->setClientAppearanceInterface(ui);
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
    setup_server();
    serverConnectionProxyAdapter->setServerEventHandler(serverEventHandler);

    CommonDateTime dt(25,9,30,19,13,00);

    serverConnectionProxyAdapter->setCurrentTime(dt);
    eventHandler->setTime(dt);

    while(1){
        loop();
    } 
}

