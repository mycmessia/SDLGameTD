//
//  MonsterMovingState.cpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 4/3/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#include "Monster.hpp"
#include "MonsterStandingState.hpp"
#include "MonsterMovingState.hpp"

MonsterMovingState::MonsterMovingState (int x, int y)
{
    _dest.x = x;
    _dest.y = y;
}

void MonsterMovingState::update(Monster &monster)
{
    SDL_Point point = SEDirector::getInstance()->getCurrentScene()->getChildByTag(1)->getPosition();
    
    _dest.x = point.x;
    _dest.y = point.y;
    
    SDL_Point curPos = monster.getPosition();
    SDL_Point newPos = curPos;
    
    if (!monster.isNearHeroine())
    {
        if (curPos.x < _dest.x)
        {
            monster.setMoveDir(Right);
            newPos.x += monster.getSpeed();
        }
        else if (curPos.x > _dest.x)
        {
            monster.setMoveDir(Left);
            newPos.x -= monster.getSpeed();
        }
        else if (curPos.y < _dest.y)
        {
            monster.setMoveDir(Down);
            newPos.y += monster.getSpeed();
        }
        else if (curPos.y > _dest.y)
        {
            monster.setMoveDir(Up);
            newPos.y -= monster.getSpeed();
        }
        
        if (monster.getCounter() % 4 == 0) monster.frame++;
        if (monster.frame == 4) monster.frame = 0;
        monster.setPosition(newPos.x, newPos.y);
    }
    else
    {
        // arrive dest
        monster.changeState(new MonsterStandingState ());
    }
}