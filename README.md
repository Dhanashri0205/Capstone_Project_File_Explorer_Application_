
# Project Title
## File Explorer Application
### Project Overview
The File Explorer application is designed to provide users with an intuitive and efficient way to manage their files and directories within a Linux environment. By leveraging the capabilities of the C++ Standard Library, particularly the <filesystem> module, this application handles various file operations with ease. It also includes logging functionality to keep track of user activities, which is critical for debugging and auditing purposes.

### Team Members
1) Dhanashri Punde 
2) Souvik Dawn
3) Praneeth Reddy

### Table Of Contents
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

#### Introduction:
The objective of this capstone project is to develop a console-based file explorer application in C++ that interacts with the Linux operating system to perform essential file management tasks. The application will allow users to list files, navigate directories, manipulate files (create, copy, move, delete), search for files, and manage file permissions, all through a command-line interface.
#### Features:




1) List Files: View all files in a specified directory.
2) Create File: Create a new file in the current directory.
3) Copy File: Copy a file from one location to another.
4) Move File: Move a file to a different location.
5) Delete File: Delete a specified file.
6) Search File: Search for a file in the directory structure.
7) Set File Permissions: Change file permissions using numeric mode (e.g., 777).
8) Change Directory: Changes the current working directory.
9) Logger Integration: Logs all operations performed for tracking and debugging.

#### Installation:
#### 1.Clone the Repository:
https://github.com/Souvik-Dawn/File-Explorer-Application.git 

#### 2.Navigate to the Project Directory:
cd FileExplorer

#### 3.Compile the Project:
make

#### 4.Run the Project:
./FileExplorer

#### Usage:
FileExplorer> list

FileExplorer> cd <directory>

FileExplorer> search <filename>

FileExplorer> chmod <filename> <mode>

FileExplorer> create <filename>

FileExplorer> copy <source> <destination>

FileExplorer> move <source> <destination>

FileExplorer> delete <filename>

FileExplorer> exit

#### Expected Output:
File Explorer Options:
1. List Files in Directory
2. Copy File
3. Move File
4. Delete File
5. Create File
6. Search File
7. Set File Permissions
8. Change Directory
9. Go Up One Directory
10. Exit
Enter your choice: 1

Enter directory path: /home/rps/FileExplorer

"/home/rps/FileExplorer/src"
"/home/rps/FileExplorer/newtest.txt"
"/home/rps/FileExplorer/Bittu.txt"
"/home/rps/FileExplorer/Souvik.txt"
"/home/rps/FileExplorer/include"
"/home/rps/FileExplorer/testing.txt"
"/home/rps/FileExplorer/souvik1.txt"
"/home/rps/FileExplorer/Saturday.txt"
"/home/rps/FileExplorer/FileExplorer"
"/home/rps/FileExplorer/file_explorer.log"
"/home/rps/FileExplorer/Souvik1.txt"
"/home/rps/FileExplorer/Praneeth.txt"

Current Directory: "/home/rps/FileExplorer"

File Explorer Options:

1. List Files in Directory
2. Copy File
3. Move File
4. Delete File
5. Create File
6. Search File
7. Set File Permissions
8. Change Directory
9. Go Up One Directory
10. Exit
Enter your choice: 2

Enter source file name: souvik1.txt

Enter destination file name: testing.txt

File copy failed.

Current Directory: "/home/rps/FileExplorer"

File Explorer Options:
1. List Files in Directory
2. Copy File
3. Move File
4. Delete File
5. Create File
6. Search File
7. Set File Permissions
8. Change Directory
9. Go Up One Directory
10. Exit
Enter your choice: 2

Enter source file name: souvik1.txt

Enter destination file name: new_souvik1.txt

File copied successfully.

Current Directory: "/home/rps/FileExplorer"

File Explorer Options:
1. List Files in Directory
2. Copy File
3. Move File
4. Delete File
5. Create File
6. Search File
7. Set File Permissions
8. Change Directory
9. Go Up One Directory
10. Exit
Enter your choice: 3

Enter source file name: Bittu.txt

Enter destination file name: new_souvik1.txt

File moved successfully.

Current Directory: "/home/rps/FileExplorer"

File Explorer Options:
1. List Files in Directory
2. Copy File
3. Move File
4. Delete File
5. Create File
6. Search File
7. Set File Permissions
8. Change Directory
9. Go Up One Directory
10. Exit
Enter your choice: 4

Enter file name to delete: new_souvik1.txt


File deleted successfully.

Current Directory: "/home/rps/FileExplorer"

File Explorer Options:
1. List Files in Directory
2. Copy File
3. Move File
4. Delete File
5. Create File
6. Search File
7. Set File Permissions
8. Change Directory
9. Go Up One Directory
10. Exit
Enter your choice: 5

Enter file name to create: Praneeth1.txt

File created successfully.

Current Directory: "/home/rps/FileExplorer"

File Explorer Options:
1. List Files in Directory
2. Copy File
3. Move File
4. Delete File
5. Create File
6. Search File
7. Set File Permissions
8. Change Directory
9. Go Up One Directory
10. Exit
Enter your choice: 6

Enter file name to search: Praneeth.txt

File found.

Current Directory: "/home/rps/FileExplorer"

File Explorer Options:
1. List Files in Directory
2. Copy File
3. Move File
4. Delete File
5. Create File
6. Search File
7. Set File Permissions
8. Change Directory
9. Go Up One Directory
10. Exit
Enter your choice: 6

Enter file name to search: test.txt

File found.

Current Directory: "/home/rps/FileExplorer"

File Explorer Options:
1. List Files in Directory
2. Copy File
3. Move File
4. Delete File
5. Create File
6. Search File
7. Set File Permissions
8. Change Directory
9. Go Up One Directory
10. Exit
Enter your choice: 7

Enter file name to set permissions: Praneeth1.txt

Enter permissions (e.g., 755): 777

Permissions set successfully.

Current Directory: "/home/rps/FileExplorer"

File Explorer Options:
1. List Files in Directory
2. Copy File
3. Move File
4. Delete File
5. Create File
6. Search File
7. Set File Permissions
8. Change Directory
9. Go Up One Directory
10. Exit
Enter your choice: 8

Enter directory to navigate to: src

Current Directory: "/home/rps/FileExplorer/src"

File Explorer Options:
1. List Files in Directory
2. Copy File
3. Move File
4. Delete File
5. Create File
6. Search File
7. Set File Permissions
8. Change Directory
9. Go Up One Directory
10. Exit
Enter your choice: 9

Current Directory: "/home/rps/FileExplorer"

File Explorer Options:
1. List Files in Directory
2. Copy File
3. Move File
4. Delete File
5. Create File
6. Search File
7. Set File Permissions
8. Change Directory
9. Go Up One Directory
10. Exit
Enter your choice: 
10

Exiting...

#### Logger:
All actions performed in the application are logged into a file named fileexplorer.log. This log includes timestamps and descriptions of each operation, which can be useful for tracking and debugging.

#### Codes
```bash
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
```
```bash
FILEEXPLORER.CPP
#include "FileExplorer.h"
#include <filesystem>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <sys/stat.h>

FileExplorer::FileExplorer(Logger& logger) : logger_(logger), currentDirectory_(std::filesystem::current_path().string()) {}

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

void FileExplorer::changeDirectory(const std::string& directory) {
    logger_.log("Changing directory to: " + directory);
    try {
        std::filesystem::current_path(directory);
        currentDirectory_ = std::filesystem::current_path().string();
        logger_.log("Directory changed successfully.");
    } catch (const std::exception& e) {
        logger_.log("Change directory failed: " + std::string(e.what()));
    }
}

void FileExplorer::goUpOneDirectory() {
    logger_.log("Going up one directory level.");
    try {
        std::filesystem::current_path("..");
        currentDirectory_ = std::filesystem::current_path().string();
        logger_.log("Directory changed successfully.");
    } catch (const std::exception& e) {
        logger_.log("Going up one directory failed: " + std::string(e.what()));
    }
}
```
```bash
Logger.H
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
```
```bash

LOGGER.CPP
#include "Logger.h"
#include <iostream>

Logger::Logger(const std::string& filename) : logFile_(filename, std::ios_base::app) {
    if (!logFile_.is_open()) {
        std::cerr << "Failed to open log file: " << filename << std::endl;
    }
}

void Logger::log(const std::string& message) {
    if (logFile_.is_open()) {
        logFile_ << message << std::endl;
    } else {
        std::cerr << "Log file is not open." << std::endl;
    }
}
```
```bash
MAIN.CPP
#include <iostream>
#include "FileExplorer.h"
#include "Logger.h"

int main() {
    Logger logger("file_explorer.log");
    FileExplorer explorer(logger);
    int choice;
    std::string path, src, dest, filename;
    int permissions;

    do {
        std::cout << "\nCurrent Directory: " << std::filesystem::current_path() << std::endl;
        std::cout << "File Explorer Options:\n";
        std::cout << "1. List Files in Directory\n";
        std::cout << "2. Copy File\n";
        std::cout << "3. Move File\n";
        std::cout << "4. Delete File\n";
        std::cout << "5. Create File\n";
        std::cout << "6. Search File\n";
        std::cout << "7. Set File Permissions\n";
        std::cout << "8. Change Directory\n";
        std::cout << "9. Go Up One Directory\n";
        std::cout << "10. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter directory path: ";
                std::cin >> path;
                explorer.listFiles(path);
                break;

            case 2:
                std::cout << "Enter source file name: ";
                std::cin >> src;
                std::cout << "Enter destination file name: ";
                std::cin >> dest;
                if (explorer.copyFile(src, dest)) {
                    std::cout << "File copied successfully.\n";
                } else {
                    std::cout << "File copy failed.\n";
                }
                break;

            case 3:
                std::cout << "Enter source file name: ";
                std::cin >> src;
                std::cout << "Enter destination file name: ";
                std::cin >> dest;
                if (explorer.moveFile(src, dest)) {
                    std::cout << "File moved successfully.\n";
                } else {
                    std::cout << "File move failed.\n";
                }
                break;

            case 4:
                std::cout << "Enter file name to delete: ";
                std::cin >> path;
                if (explorer.deleteFile(path)) {
                    std::cout << "File deleted successfully.\n";
                } else {
                    std::cout << "File delete failed.\n";
                }
                break;

            case 5:
                std::cout << "Enter file name to create: ";
                std::cin >> path;
                if (explorer.createFile(path)) {
                    std::cout << "File created successfully.\n";
                } else {
                    std::cout << "File creation failed.\n";
                }
                break;

            case 6:
                std::cout << "Enter file name to search: ";
                std::cin >> filename;
                if (explorer.searchFile(filename)) {
                    std::cout << "File found.\n";
                } else {
                    std::cout << "File not found.\n";
                }
                break;

            case 7:
                std::cout << "Enter file name to set permissions: ";
                std::cin >> path;
                std::cout << "Enter permissions (e.g., 755): ";
                std::cin >> permissions;
                if (explorer.setPermissions(path, permissions)) {
                    std::cout << "Permissions set successfully.\n";
                } else {
                    std::cout << "Setting permissions failed.\n";
                }
                break;

            case 8:
                std::cout << "Enter directory to navigate to: ";
                std::cin >> path;
                explorer.changeDirectory(path);
                break;

            case 9:
                explorer.goUpOneDirectory();
                break;

            case 10:
                std::cout << "Exiting...\n";
                break;

            default:
                std::cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 10);

    return 0;
}
```
```bash
MAKE FILE
# Makefile for the File Explorer project with Google Test

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude
TARGET = FileExplorer
TEST_TARGET = test_fileexplorer

# Object files
OBJS = src/main.o src/FileExplorer.o src/Logger.o
TEST_OBJS = tests/test_fileexplorer.o src/FileExplorer.o src/Logger.o

# Build the main target
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Build the test target
$(TEST_TARGET): $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -lgtest -lgtest_main -pthread -o $(TEST_TARGET) $(TEST_OBJS)

# Compile main.cpp
src/main.o: src/main.cpp include/FileExplorer.h include/Logger.h
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o src/main.o

# Compile FileExplorer.cpp
src/FileExplorer.o: src/FileExplorer.cpp include/FileExplorer.h include/Logger.h
	$(CXX) $(CXXFLAGS) -c src/FileExplorer.cpp -o src/FileExplorer.o

# Compile Logger.cpp
src/Logger.o: src/Logger.cpp include/Logger.h
	$(CXX) $(CXXFLAGS) -c src/Logger.cpp -o src/Logger.o

# Compile the test file
tests/test_fileexplorer.o: tests/test_fileexplorer.cpp include/FileExplorer.h include/Logger.h
	$(CXX) $(CXXFLAGS) -c tests/test_fileexplorer.cpp -o tests/test_fileexplorer.o

# Clean the build directory
clean:
	rm -f $(TARGET) $(TEST_TARGET) src/.o tests/.o

# Run the file explorer
run: $(TARGET)
	./$(TARGET)

# Run the tests
test: $(TEST_TARGET)
	./$(TEST_TARGET)

# PHONY targets
.PHONY: clean run test
```
#### File Structure:

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
├── Makefile             # Makefile to automate the build process

```

#### Dependencies:
1) C++11 or later
2) GCC Compiler (g++)

#### Contributing:
Contributions are always welcome!

If you would like to contribute to this project, please fork the repository and submit a pull request. For major changes, please open an issue to discuss what you would like to change.

#### License:
This 'File Explorer Application' project is licensed under the our group - see the LICENSE file for details.

#### Reference:

1) Trainning
2) Youtube 
3) Google


### Thanks Note:
Thank You, 

Trainer -  Shweatank Sir

For your guidance and support through out this project.

