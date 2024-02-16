#include <iostream>
#include <stdlib.h> // for exit
#include <string>

#include "stringUtils.h"

enum CommandResult
{
    COMMAND_SUCCESS,
    UNRECOGNISED_COMMAND
};

enum Command
{
    ADD,
    DELETE,
    LIST,
    SEARCH,
    QUIT
};

bool
Add()
{
    std::cout << "add" << std::endl;
    std::string newPassword;
    std::cin >> newPassword;
    std::cout << "password is " << newPassword << std::endl;
    return true;
}

void
ShowHelp()
{
    std::cout <<
        "Options:\n"
        << "A: Add password\n"
        << "D: Delete password\n"
        << "L: List available passwords\n"
        << "S: Search for password\n"
        << "Q: Quit" << std::endl;
    return;
}

int
HandleCommand(const std::string& aCommand)
{
    // TODO: remove
    std::string commandLower = aCommand;
    commandLower = StringUtils::toLower(commandLower);

    if (commandLower == "exit" || commandLower == "quit" || commandLower == "q") {
        std::cout << "Exiting." << std::endl;
        exit(EXIT_SUCCESS);
    }

    if (commandLower == "add" || commandLower == "a") {
        Add();
        return 0;
    }

    return 1;
}

int
main(int argc, char* argv[])
{
    std::cout << "Password Manager" << std::endl;

    while(true) {
        std::cout << "> ";
        std::cout.flush();
        std::string input;
        std::getline(std::cin, input);

        switch(HandleCommand(input)) {
            case (COMMAND_SUCCESS):
                continue;
            case (UNRECOGNISED_COMMAND):
                std::cout << "Unrecognised command '" << input << "'. Type h or help for options." << std::endl;
        }
    }
    return 0;
}
