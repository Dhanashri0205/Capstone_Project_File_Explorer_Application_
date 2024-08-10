#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>

class Logger {
public:
    explicit Logger(const std::string& filename);
    void log(const std::string& message);

private:
    std::ofstream logFile_;
};

#endif // LOGGER_H

LOGGER.H
