#pragma once 

#include "string"

enum class LoggingLevel{
    TURN_OFF = 0,
    ERROR = 1,
    INFO = 2,
    DEBUG = 3
};

class LoggingLevelStringMapper{
public: static std::string map(LoggingLevel level){
    switch (level)
    {
    case LoggingLevel::INFO:
        return "INFO ";
    case LoggingLevel::DEBUG:
        return "DEBUG";
    case LoggingLevel::ERROR:
        return "ERROR";
    default:
        return "UNKNOWN";
    }
}
};