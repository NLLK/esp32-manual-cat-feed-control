#include "../../../application/server/eventHandler/EventHandler.hpp"
#include "../../../application/server/service/DaysMealsService.hpp"
#include "../common/adapters/DaysMealsRepositoryImpl.hpp"

ApplicationServer::EventHandler* serverEventHandler;
DaysMealsService* daysMealsService;
DaysMealsRepository* daysMealsRepository;

void setup_server(){
    daysMealsRepository = new DaysMealsRepositoryInMemoryImpl();
    daysMealsService = new DaysMealsService(daysMealsRepository);

    serverEventHandler = new ApplicationServer::EventHandler(daysMealsService);
}