//
//  Command.hpp
//  Shell
//
//  Created by Gregor Konzett on 14.09.20.
//  Copyright © 2020 Gregor Konzett. All rights reserved.
//

#ifndef Command_hpp
#define Command_hpp

#include <vector>
#include <string>
#include <sstream>
#include <iostream>

using std::vector;
using std::string;

class Command {
public:
    Command(string input);
    vector<char*> args();
    char* command();
    
private:
    vector<char*> args_;
    
    void parse_input(string input);
};

#endif /* Command_hpp */
