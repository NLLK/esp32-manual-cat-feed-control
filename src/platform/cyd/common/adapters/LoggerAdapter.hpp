#pragma once

#include "../../../../middleware/logger/LoggerPort.hpp"

#include "Arduino.h"

class LoggerAdapter : public LoggerPort{
public: 
    LoggerAdapter(){}

    void output(std::string string) override {
        Serial.println(string.c_str());
    }
};
