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
