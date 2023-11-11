#include <iostream>
#include <stdlib.h> // for exit
#include <string>

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
    std::string newPassword;
    std::cin >> newPassword;
    std::cout << newPassword << std::endl;
    return true;
}

void
ShowHelp()
{
    std::cout <<
        "Options:" << std::endl
        << "A: Add password" << std::endl
        << "D: Delete password" << std::endl
        << "L: List available passwords" << std::endl
        << "S: Search for password" << std::endl
        << "Q: Quit" << std::endl;
    return;
}

int
HandleCommand(const std::string& aCommand)
{
    std::cout << aCommand << std::endl;
    if (aCommand == "exit" || aCommand == "quit" || aCommand == "q") {
        std::cout << "Exiting." << std::endl;
        exit(EXIT_SUCCESS);
    }
    return 0;
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
                std::cout << "Unrecognised command '" << input << "'. Type H or help for options." << std::endl;
        }
    }
    return 0;
}
