//
//  MonsterAttackingState.hpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 4/6/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#ifndef MonsterAttackingState_hpp
#define MonsterAttackingState_hpp

#include "MonsterState.hpp"

class MonsterAttackingState : public MonsterState
{
public:
    MonsterAttackingState () {};
    virtual void update (Monster& monster);
};

#endif /* MonsterAttackingState_hpp */
