#pragma once

#include "Arduino.h"

#include "./Task.hpp"
#include "../../../../application/client/eventHandler/EventHandler.hpp"
#include "../../../../application/client/ports/ServerConnectionPort.hpp"
#include "../../../../common/utils/CommonDateTime.hpp"

class ClientUpdateTimeTask: public Task{
public:
    ClientUpdateTimeTask(EventHandlerTimeUpdatePort* timeUpdatePort = nullptr, ServerConnectionPort* serverConnectionPort = nullptr, uint32_t delayBeforeStart = 200)
    : Task("ClientTimeUpdate", 4096, 1), timeUpdatePort(timeUpdatePort), serverConnectionPort(serverConnectionPort){
        setDelayBeforeStart(delayBeforeStart);
    }

    void setServerConnectionPort(ServerConnectionPort* serverConnectionPort){
        this->serverConnectionPort = serverConnectionPort;
    }

private:
    EventHandlerTimeUpdatePort* timeUpdatePort = nullptr;
    ServerConnectionPort* serverConnectionPort = nullptr;
    CommonDateTime currentTime;

protected:
    void run() override {
        Serial.println("Client Time update task started");
        
        attemptToSyncronizeTimeWithServer(60);

        while(1){
            timeUpdatePort->updateTime(currentTime);

            vTaskDelay((60-currentTime.seconds) * TASK_CONST_SECOND);
            incrementMinutes();
        }
    }
private:
    void setCurrentTimeFromServer(){
        currentTime = serverConnectionPort->getCurrentTime();   
    }

    void attemptToSyncronizeTimeWithServer(uint8_t attempts){
        uint8_t wastedAttempts = 0;

        while(wastedAttempts < attempts){
            setCurrentTimeFromServer();
            if (!currentTime.isEmpty()){
                break;
            }
            wastedAttempts++;
            vTaskDelay(TASK_CONST_SECOND);
        }
    }

    void incrementMinutes(){
        uint8_t day = currentTime.day;

        currentTime.incrementMinutes(1);

        if (day != currentTime.day){
            attemptToSyncronizeTimeWithServer(5);
        }
    }
};
