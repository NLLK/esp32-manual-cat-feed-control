#pragma once

#include "stdio.h"

#include "middleware/logger/LoggerPort.hpp"

class LoggerAdapter : public LoggerPort{
public: 
    LoggerAdapter(){}

    void output(std::string string) override {
        printf("%s\n", string.c_str());
        fflush(stdout);
    }
};
