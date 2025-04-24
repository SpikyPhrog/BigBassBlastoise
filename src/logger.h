#pragma once
#include <fstream>
#include <ctime>
#include <iostream>
#include <sstream>
#include "loggerLevels.h"
#include <utility>

class Logger
{
public:
    Logger(const std::string& fileName);
    ~Logger();

    static void Log(const LoggerLevel& logLevel, char* fmt, ...);
    
    static std::ofstream file;
private:
    static std::string getTimestamp();
};