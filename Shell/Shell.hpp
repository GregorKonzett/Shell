//
//  Shell.hpp
//  Shell
//
//  Created by Gregor Konzett on 14.09.20.
//  Copyright © 2020 Gregor Konzett. All rights reserved.
//

#ifndef Shell_hpp
#define Shell_hpp

#include <iostream>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>

#include "Command.hpp"

using std::vector;
using std::cout;
using std::string;
using std::cin;

class Shell {
public:
    void run();
    
private:
    vector<Command> commandHistory_;
    void executeCommand(Command command);
    
    Command readCommand();
};

#endif /* Shell_hpp */
