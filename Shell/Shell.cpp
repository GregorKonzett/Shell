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
    //commandHistory_.push_back(command);
    return command;
}

int Shell::exec(Command command) {
    return execvp(command.args().at(0), command.args().data());
}

void Shell::startProcess(Command command) {
    pid_t pid, wpid;
    int status;
    
    pid = fork();
    if (pid == 0) {
        status = exec(command);
        
        if (status == -1) {
            perror("a");
        } else {
            cout << "Status: " << status << std::endl;
        }
      exit(EXIT_FAILURE);
    } else if (pid < 0) {
      // Error forking
      perror("b");
    } else {
      // Parent process
      do {
        wpid = waitpid(pid, &status, WUNTRACED);
      } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
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
    startProcess(command);
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
