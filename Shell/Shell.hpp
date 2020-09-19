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
#include "ProcessHandler.hpp"
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
    ProcessHandler processHandler_;
    
    void executeCommand(Command command);
    bool isCommand(char* input, char* command);
    Command readCommand();
};

#endif /* Shell_hpp */
