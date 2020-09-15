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

using std::vector;
using std::string;

class Command {
public:
    Command(string input);
    vector<string> args();
    
private:
    vector<string> args_;
    
    void parse_input(string input);
};

#endif /* Command_hpp */
