#include "FileExplorer.h"
#include <iostream>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

void FileExplorer::listFiles(const std::string& directory)
{
    for (const auto& entry : fs::directory_iterator(directory))
    {
        std::cout << entry.path().filename().string() << std::endl;
    }
}

void FileExplorer::changeDirectory(const std::string& path)
{
    fs::current_path(path);
}

void FileExplorer::searchFiles(const std::string& directory, const std::string& filename)
{
    for (const auto& entry : fs::recursive_directory_iterator(directory))
    {
        if (entry.path().filename() == filename)
       	{
            std::cout << "Found: " << entry.path().string() << std::endl;
            return;
        }
    }
    std::cout << "File not found!" << std::endl;
}

void FileExplorer::setPermissions(const std::string& filename, int mode)
{
    fs::permissions(filename, static_cast<fs::perms>(mode));
}

void FileExplorer::createFile(const std::string& filename)
{
    std::ofstream file(filename);
   
    if (file)
    {
        file.close();
    }
}

void FileExplorer::copyFile(const std::string& source, const std::string& destination)
{
    fs::copy(source, destination);
}

void FileExplorer::moveFile(const std::string& source, const std::string& destination)
{
    fs::rename(source, destination);
}

void FileExplorer::deleteFile(const std::string& filename)
{
    fs::remove(filename);
}
