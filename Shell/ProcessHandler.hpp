//
//  ProcessHandler.hpp
//  Shell
//
//  Created by Gregor Konzett on 19.09.20.
//  Copyright © 2020 Gregor Konzett. All rights reserved.
//

#ifndef ProcessHandler_hpp
#define ProcessHandler_hpp


#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "Command.hpp"

class ProcessHandler {
public:
    void startProcess(Command command);
    
private:
    int exec(Command command);
};



#endif /* ProcessHandler_hpp */
