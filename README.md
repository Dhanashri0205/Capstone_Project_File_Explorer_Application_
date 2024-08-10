
# Project Title

File Explorer Application

#### Project Overview

The File Explorer application is designed to provide users with an intuitive and efficient way to manage their files and directories within a Linux environment. By leveraging the capabilities of the C++ Standard Library, particularly the <filesystem> module, this application handles various file operations with ease. It also includes logging functionality to keep track of user activities, which is critical for debugging and auditing purposes.
#### Team Members
1) Dhanashri Punde
2) Souvik Dawn
3) Praneeth Reddy
#### Table Of Contents
1) Introduction
2) Features
3) Installation
4) Usage
5) Expected Output
6) Logger
7) Codes
8) File Structure
9) Dependencies
10) Contributing
11) License
12) Reference
13) Thanks Note

#### Introduction
The objective of this capstone project is to develop a console-based file explorer application in C++ that interacts with the Linux operating system to perform essential file management tasks. The application will allow users to list files, navigate directories, manipulate files (create, copy, move, delete), search for files, and manage file permissions, all through a command-line interface.
#### Features
1) List Files: View all files in a specified directory.
2) Create File: Create a new file in the current directory.
3) Copy File: Copy a file from one location to another.
4) Move File: Move a file to a different location.
5) Delete File: Delete a specified file.
6) Search File: Search for a file in the directory structure.
7) Set File Permissions: Change file permissions using numeric mode (e.g., 777).
8) Change Directory: Changes the current working directory.
9) Logger Integration: Logs all operations performed for tracking and debugging.

 #### Installation
 1.Clone the Repository

https://github.com/Souvik-Dawn/File-Explorer-Application.git 

2.Navigate to the Project Directory

cd FileExplorer

3.Compile the Project

g++ -o FileExplorer src/main.cpp src/FileExplorer.cpp src/Logger.cpp -Iinclude


4.Run the Project

./FileExplorer

#### Usage
1) FileExplorer> list
2) FileExplorer> cd <directory>
3) FileExplorer> search <filename>
4) FileExplorer> chmod <filename> <mode>
5) FileExplorer> create <filename>
6) FileExplorer> copy <source> <destination>
7) FileExplorer> move <source> <destination>
8) FileExplorer> delete <filename>
9) FileExplorer> exit

#### EXpected Output
File Explorer Options:
1. List Files in Directory
2. Copy File
3. Move File
4. Delete File
5. Create File
6. Search File
7. Set File Permissions
8. Exit
Enter your choice: 5
Enter file name to create: dhanashri1.txt
File created successfully.

File Explorer Options:
1. List Files in Directory
2. Copy File
3. Move File
4. Delete File
5. Create File
6. Search File
7. Set File Permissions
8. Exit

#### Logger

All actions performed in the application are logged into a file named fileexplorer.log. This log includes timestamps and descriptions of each operation, which can be useful for tracking and debugging.

#### Codes

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

private:

    Logger& logger_;
};

#endif // FILEEXPLORER_H

LOGGER.H

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

```bash
FILEEXPLORER.CPP
#include "FileExplorer.h"
#include <filesystem>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <sys/stat.h>

FileExplorer::FileExplorer(Logger& logger) : logger_(logger) {}

void FileExplorer::listFiles(const std::string& directory) {
    logger_.log("Listing files in directory: " + directory);
    try {
        for (const auto& entry : std::filesystem::directory_iterator(directory)) {
            std::cout << entry.path() << std::endl;
        }
    } catch (const std::exception& e) {
        logger_.log("Listing files failed: " + std::string(e.what()));
    }
}

bool FileExplorer::copyFile(const std::string& src, const std::string& dest) {
    logger_.log("Copying file from " + src + " to " + dest);
    try {
        std::filesystem::copy(src, dest);
        logger_.log("File copied successfully.");
        return true;
    } catch (const std::exception& e) {
        logger_.log("Copy failed: " + std::string(e.what()));
        return false;
    }
}

bool FileExplorer::moveFile(const std::string& src, const std::string& dest) {
    logger_.log("Moving file from " + src + " to " + dest);
    try {
        std::filesystem::rename(src, dest);
        logger_.log("File moved successfully.");
        return true;
    } catch (const std::exception& e) {
        logger_.log("Move failed: " + std::string(e.what()));
        return false;
    }
}

bool FileExplorer::deleteFile(const std::string& path) {
    logger_.log("Deleting file: " + path);
    try {
        std::filesystem::remove(path);
        logger_.log("File deleted successfully.");
        return true;
    } catch (const std::exception& e) {
        logger_.log("Delete failed: " + std::string(e.what()));
        return false;
    }
}

bool FileExplorer::createFile(const std::string& path) {
    logger_.log("Creating file: " + path);
    try {
        std::ofstream file(path);
        file.close();
        logger_.log("File created successfully.");
        return true;
    } catch (...) {
        logger_.log("File creation failed.");
        return false;
    }
}

bool FileExplorer::searchFile(const std::string& filename) {
    logger_.log("Searching for file: " + filename);
    try {
        for (const auto& entry : std::filesystem::recursive_directory_iterator(".")) {
            if (entry.path().filename() == filename) {
                logger_.log("File found: " + entry.path().string());
                return true;
            }
        }
        logger_.log("File not found.");
        return false;
    } catch (const std::exception& e) {
        logger_.log("Search failed: " + std::string(e.what()));
        return false;
    }
}

bool FileExplorer::setPermissions(const std::string& path, int permissions) {
    logger_.log("Setting permissions for file: " + path);
    try {
        std::filesystem::permissions(path, static_cast<std::filesystem::perms>(permissions), std::filesystem::perm_options::replace);
        logger_.log("Permissions set successfully.");
        return true;
    } catch (const std::exception& e) {
        logger_.log("Setting permissions failed: " + std::string(e.what()));
        return false;
    }
}
```

```bash
LOGGER.CPP
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
```
```bash
MAIN.CPP
#include "file_explorer.h"
#include "Logger.h"
#include <iostream>
#include <string>
#include <sstream>

int main() {
    Logger logger("fileexplorer.log");
    FileExplorer explorer;
    
    std::string input;
    std::string command;
    std::string argument;

    logger.log("File Explorer application started");

    while (true)
    {
        std::cout << "FileExplorer> ";
        std::getline(std::cin, input);

        std::istringstream iss(input);
        iss >> command;


        if (command == "list")
       	{
            explorer.listFiles(".");
            logger.log("Listed files in the current directory");
        }

       	else if (command == "cd")
       	{
            std::cout << "Enter directory: ";
            std::getline(std::cin, argument);
            explorer.changeDirectory(argument);
            std::cout << "Changed directory to " << argument << std::endl;
            logger.log("Changed directory to " + argument);
        }

       	else if (command == "search")

       	{
            std::cout << "Enter filename to search: ";
            std::getline(std::cin, argument);
            explorer.searchFiles(".", argument);
            logger.log("Searched for file: " + argument);
        }

       	else if (command == "chmod")
       	{
            std::string filename;
            int mode;
            std::cout << "Enter filename: ";
            std::getline(std::cin, filename);
            std::cout << "Enter mode (e.g., 755): ";
            std::cin >> mode;
            std::cin.ignore(); // Ignore newline left in the buffer
            explorer.setPermissions(filename, mode);
            std::cout << "Changed permissions for " << filename << " to " << mode << std::endl;
            logger.log("Changed permissions for file: " + filename + " to " + std::to_string(mode));
        }

       	else if (command == "create")
       	{
            iss >> argument;
            explorer.createFile(argument);
            std::cout << "File created: " << argument << std::endl;
            logger.log("Created file: " + argument);
        }

       	else if (command == "copy")
       	{
            std::string source, destination;
            iss >> source >> destination;
            explorer.copyFile(source, destination);
            std::cout << "File copied from " << source << " to " << destination << std::endl;
            logger.log("Copied file from " + source + " to " + destination);
        }

       	else if (command == "move")
       	{
            std::string source, destination;
            iss >> source >> destination;
            explorer.moveFile(source, destination);
            std::cout << "File moved from " << source << " to " << destination << std::endl;
            logger.log("Moved file from " + source + " to " + destination);
        }
       
	else if (command == "delete")
       	{
            iss >> argument;
            explorer.deleteFile(argument);
            std::cout << "File deleted: " << argument << std::endl;
            logger.log("Deleted file: " + argument);
        }
       
	else if (command == "exit")
       	{
            logger.log("Exiting application");
            break;
        }
       
	else
       	{
            std::cout << "Unknown command: " << command << std::endl;
        }
    }

    return 0;
}
```

#### File Structure
```bash
FileExplorer/
│
├── include/
│   ├── FileExplorer.h   # Header file for the FileExplorer class
│   ├── Logger.h         # Header file for the Logger class
│
├── src/
│   ├── FileExplorer.cpp # Implementation of the FileExplorer class
│   ├── Logger.cpp       # Implementation of the Logger class
│   ├── main.cpp         # Main entry point for the application
│
├── file_explorer.log    # Log file generated by the application (created during runtime)
├── FileExplorer         # Executable file generated after compilation
├── README.md            # This README file
```
#### Dependencies

1)  C++11 or later
 2) GCC Compiler (g++)

 #### Contributing
 Contributions are always welcome!

 If you would like to contribute to this project, please fork the repository and submit a pull request. For major changes, please open an issue to discuss what you would like to change.

 #### License
 This 'File Explorer Application' project is licensed under the our group - see the LICENSE file for details.

 #### Reference
 1) Training
2) Youtube 
3) Google

#### Thanks Note
Thank You , Trainer -  Shweatank Sir

For your guidance and support through out this project.

