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
    if (!monster.isNearHeroine())
    {
        SDL_Point point = SEDirector::getInstance()->getCurrentScene()->getChildByTag(1)->getPosition();
        monster.changeState(new MonsterMovingState (point.x, point.y));
    }
    //    std::cout << "update standingState" << std::endl;
}
