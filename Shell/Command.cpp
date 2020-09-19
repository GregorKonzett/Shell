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
    std::istringstream iss(input);
    
    for(std::string s; iss >> s;) {
        size_t size = s.size();
        char *buf = new char[size + 1];
        memcpy(buf, s.c_str(), size + 1);
        
        args_.push_back(buf);
    }
    
    args_.push_back(NULL);
}

char* Command::command() {
    return args_.front();
}

vector<char*> Command::args() {
    return args_;
}
