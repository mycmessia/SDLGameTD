//
//  MonsterStandingState.hpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 4/3/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#ifndef MonsterStandingState_hpp
#define MonsterStandingState_hpp

#include "MonsterState.hpp"

class MonsterStandingState : public MonsterState
{
public:
    virtual void update (Monster& heroine);
};

#endif /* MonsterStandingState_hpp */