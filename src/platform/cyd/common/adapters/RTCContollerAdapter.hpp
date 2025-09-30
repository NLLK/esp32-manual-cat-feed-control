#pragma once

#include "../../../../application/client/ports/RTCContollerPort.hpp"

#include "../tasks/RtcTimeSetTask.hpp"

class RTCContollerAdapter : public RTCControllerPort{
public: 
    RTCContollerAdapter(RtcTimeSetTask* timeSetTask = nullptr):timeSetTask(timeSetTask){}

    void setTimeSetTask(RtcTimeSetTask* timeSetTask ){
        this->timeSetTask = timeSetTask;
    }

    void setCurrentTime(CommonDateTime time) override {
        timeSetTask->setTime(time);
        timeSetTask->start();
    }

private:
    RtcTimeSetTask* timeSetTask = nullptr;
};
