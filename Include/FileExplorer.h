FILEEXPLORER.H
#ifndef FILEEXPLORER_H
#define FILEEXPLORER_H

#include <string>
#include "Logger.h"

class FileExplorer {
public:
    explicit FileExplorer(Logger& logger);

    void listFiles(const std::string& directory);
    bool copyFile(const std::string& src, const std::string& dest);
    bool moveFile(const std::string& src, const std::string& dest);
    bool deleteFile(const std::string& path);
    bool createFile(const std::string& path);
    bool searchFile(const std::string& filename);
    bool setPermissions(const std::string& path, int permissions);
    void changeDirectory(const std::string& directory);
    void goUpOneDirectory();

private:
    Logger& logger_;
    std::string currentDirectory_;
};

#endif // FILEEXPLORER_H
