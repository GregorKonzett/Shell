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

bool Shell::isCommand(char *input, char *command) {
    while(*input != '\0') {
        if(*input != *command) return false;
        input++;
        command++;
    }
    
    return true;
}

void Shell::executeCommand(Command command) {
    if(isCommand(command.command(), const_cast<char*>("cd"))) {
        chdir(command.args().at(1));
    } else {
        processHandler_.startProcess(command);
    }
}

void Shell::run() {
    int status = 1;
    string command;
    char buffer[255];
    
    do {
        cout << getcwd(buffer, 255) << "> ";
        Command command = readCommand();
        
        if(command.args().at(0) == NULL) continue;
        
        executeCommand(command);
    } while(status);
}
