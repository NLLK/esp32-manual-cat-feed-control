#include "../../../application/server/eventHandler/EventHandler.hpp"
#include "../../../application/server/service/DaysMealsService.hpp"
#include "./adapters/DaysMealsRepositoryImpl.hpp"

ApplicationServer::EventHandler* serverEventHandler;
DaysMealsService* daysMealsService;
DaysMealsRepository* daysMealsRepository;

RTCContollerAdapter* rtc;

void setup_server(){
    daysMealsRepository = new DaysMealsRepositoryImpl();
    daysMealsService = new DaysMealsService(daysMealsRepository);

    rtc = new RTCContollerAdapter();

    serverEventHandler = new ApplicationServer::EventHandler(daysMealsService, rtc);
    
}