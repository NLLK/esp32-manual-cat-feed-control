#pragma once

#include <cstdarg>

#include "./LoggerPort.hpp"
#include "./LoggingLevel.h"

#define LOG Logger::getInstance()

class Logger{
public:
    static Logger& getInstance(){
        static Logger instance;
        return instance;
    }
    //DI
    static void setLoggerPort(LoggerPort* _port){
        port = _port;
    }
    static void setLoggingLevel(LoggingLevel level){
        loggingLevel = level;
    }

    // Public functions
    void info(std::string format, ...){
        va_list args;
        va_start(args, format);
        log(LoggingLevel::INFO, format, &args);
        va_end(args);
    }

    void debug(std::string format, ...){
        va_list args;
        va_start(args, format);
        log(LoggingLevel::DEBUG, format, &args);
        va_end(args);
    }

    void error(std::string format, ...){
        va_list args;
        va_start(args, format);
        log(LoggingLevel::ERROR, format, &args);
        va_end(args);
    }

private:
    Logger() = default;

    inline static LoggerPort* port = nullptr;
    inline static LoggingLevel loggingLevel = LoggingLevel::INFO;

private:

    std::string logHeader(LoggingLevel level){
        return "[" + LoggingLevelStringMapper::map(level) + "] ";
    }

    bool isNeedToLogThisLevel(LoggingLevel level){
        if (level == LoggingLevel::TURN_OFF) return false;
        return static_cast<int>(level) <= static_cast<int>(loggingLevel);
    }

    void log(LoggingLevel level, std::string format, va_list* args){
        char buffer[1024] = {'\0',};
        vsnprintf(buffer, sizeof(buffer), format.c_str(), *args);
        std::string str = std::string(buffer);
        log(level, str);
    }

    void log(LoggingLevel level, const std::string& data){
        if (!isNeedToLogThisLevel(level)) return;
        std::string res = logHeader(level) + data; 
        port->output(res);
    }
};