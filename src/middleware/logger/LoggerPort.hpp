#pragma once

#include "string"

class LoggerPort{
public:
    virtual ~LoggerPort(){}
    virtual void output(std::string string) = 0;
};