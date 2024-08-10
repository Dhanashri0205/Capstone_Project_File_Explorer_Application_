LOGGER.CPP
#include <iostream>
#include <fstream>
#include "Logger.h"

Logger::Logger(const std::string& filename) : logFile_(filename, std::ios_base::app) {}

void Logger::log(const std::string& message) {
    if (logFile_.is_open()) {
        logFile_ << message << std::endl;
    } else {
        std::cerr << "Failed to open log file." << std::endl;
    }
}
