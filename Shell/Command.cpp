//
//  Command.cpp
//  Shell
//
//  Created by Gregor Konzett on 14.09.20.
//  Copyright © 2020 Gregor Konzett. All rights reserved.
//

#include "Command.hpp"

Command::Command(string input) {
    parse_input(input);
}

void Command::parse_input(string input) {
    size_t pos = 0;
    
    while(input.length() > 0) {
        pos = input.find(" ");
        
        if(pos == string::npos) {
            args_.push_back(input);
            break;
        } else {
            args_.push_back(input.substr(0, pos));
            input.erase(0, pos + 1);
        }
    }
}

vector<string> Command::args() {
    return args_;
}
