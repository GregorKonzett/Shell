//
//  ProcessHandler.cpp
//  Shell
//
//  Created by Gregor Konzett on 19.09.20.
//  Copyright © 2020 Gregor Konzett. All rights reserved.
//

#include "ProcessHandler.hpp"

int ProcessHandler::exec(Command command) {
    return execvp(command.args().at(0), command.args().data());
}

void ProcessHandler::startProcess(Command command) {
    int status;
    
    pid_t pid = fork();
    if (pid == 0) {
        if (exec(command) == -1) {
            perror("shell");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("shell");
    } else {
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}
