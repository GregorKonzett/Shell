//
//  Shell.cpp
//  Shell
//
//  Created by Gregor Konzett on 14.09.20.
//  Copyright © 2020 Gregor Konzett. All rights reserved.
//

#include "Shell.hpp"

Command Shell::readCommand() {
    string input;
    std::getline(std::cin, input);
    Command command(input);
    commandHistory_.push_back(command);
    return command;
}

void Shell::executeCommand(Command command) {
    std::system(command.args().at(0).c_str());
}

void Shell::run() {
    int status = 1;
    string command;
    char buffer[255];
    
    do {
        cout << getcwd(buffer, 255) << "> ";
        Command command = readCommand();
        executeCommand(command);
    } while(status);
}
