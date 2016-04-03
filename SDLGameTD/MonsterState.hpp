//
//  MonsterState.hpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 4/3/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#ifndef MonsterState_hpp
#define MonsterState_hpp

#include "SimpleEngine.h"

class Monster;

class MonsterState
{
public:
    virtual MonsterState* handleInput (Monster& heroine, SDL_Event e) {return new MonsterState ();}
    virtual void update (Monster& heroine) {}
};


#endif /* MonsterState_hpp */
