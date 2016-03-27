//
//  Command.hpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 3/23/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#ifndef Command_hpp
#define Command_hpp

#include <iostream>

class Command
{
public:
    virtual ~Command() {};
    virtual void execute () = 0;
};

class JumpCommand : public Command
{
public:
    void execute();
};

class FireCommand : public Command
{
public:
    void execute();
};

#endif /* Command_hpp */
