//
//  MonsterStandingState.cpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 4/3/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#include "Monster.hpp"
#include "MonsterMovingState.hpp"
#include "MonsterStandingState.hpp"

void MonsterStandingState::update (Monster& monster)
{
    if (monster.getTarget())
    {
        SDL_Point point = monster.getTarget()->getPosition();
        monster.changeState(new MonsterMovingState (point.x, point.y));
    }
    else
    {
        // looking for the target
        
    }
}
