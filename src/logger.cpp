#include "logger.h"
#include <cstdarg>
#include <chrono>
#include <iomanip>

std::ofstream Logger::file("logs.txt");

Logger::Logger(const std::string &fileName)
{

}

Logger::~Logger()
{
    file.close();
}

void Logger::Log(const LoggerLevel &logLevel, char *fmt, ...)
{
    std::ostringstream logEntry;
    logEntry << "[" << getTimestamp() << "]" << GetStringLoggerLevel(logLevel) << ": ";

    va_list args;
    va_start(args, fmt);

    for (int j = 0; j < fmt[j] != '\0'  ; ++j)
    {
        switch (fmt[j])
        {
        case 'i':
        {
            int num = va_arg(args, int);
            logEntry << ' ' << num;
        }
        break;

        case 's':
        {
            char* str = va_arg(args, char*);
            logEntry << ' ' << str;
        }
        break;
        
        case 'c':
        {    
            char c = va_arg(args, char);
            logEntry << ' ' << c;
        }
        break;

        case 'f':
        {    
            float f = va_arg(args, double);
            logEntry << ' ' << f;
        }
        break;

        case 'd':
        {    
            double d = va_arg(args, double);
            logEntry << ' ' << d;
        }
        break;

        default:
        break;
        }
    }

    logEntry << '\n';

    printf("%s", logEntry.str().c_str());

    if (file.is_open())
    {
        file << logEntry.str();
        file.flush();
    }

    va_end(args);
}

std::string Logger::getTimestamp()
{
    // get a precise timestamp as a string
    const auto now = std::chrono::system_clock::now();
    const auto nowAsTimeT = std::chrono::system_clock::to_time_t(now);
    const auto nowMs = std::chrono::duration_cast<std::chrono::milliseconds>(
        now.time_since_epoch()) % 1000;
    std::stringstream nowSs;
    nowSs
        << std::put_time(std::localtime(&nowAsTimeT), "%d %m %Y %T")
        << '.' << std::setfill('0') << std::setw(3) << nowMs.count();
    return nowSs.str();
    
}
