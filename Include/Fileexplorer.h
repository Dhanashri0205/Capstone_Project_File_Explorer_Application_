#ifndef FILEEXPLORER_H
#define FILEEXPLORER_H

#include <string>

class FileExplorer
{
public:
    void listFiles(const std::string& directory);
    void changeDirectory(const std::string& directory);
    void searchFiles(const std::string& directory, const std::string& filename);
    void setPermissions(const std::string& filename, int mode);
    void createFile(const std::string& filename);
    void copyFile(const std::string& source, const std::string& destination);
    void moveFile(const std::string& source, const std::string& destination);
    void deleteFile(const std::string& filename);
};

#endif // FILEEXPLORER_H
