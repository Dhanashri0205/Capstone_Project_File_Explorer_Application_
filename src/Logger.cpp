#include "Logger.h"
#include <iostream>
#include <ctime>

Logger::Logger(const std::string& filename)
{
    logFile.open(filename, std::ios::app); // Open in append mode
    if (!logFile)
    {
        std::cerr << "Error: Could not open log file: " << filename << std::endl;
    }
}

Logger::~Logger()
{
    if (logFile.is_open())
    {
        logFile.close();
    }
}

void Logger::log(const std::string& message)
{
    if (logFile)
    {
        // Get current time
        std::time_t now = std::time(nullptr);
        char timeStr[100];
        std::strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
        
        // Write timestamped message to log file
        logFile << "[" << timeStr << "] " << message << std::endl;
    }
}
