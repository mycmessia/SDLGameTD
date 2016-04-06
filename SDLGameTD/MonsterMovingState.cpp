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

MonsterMovingState::MonsterMovingState () {}

void MonsterMovingState::update(Monster &monster)
{
    if (monster.getTarget())
    {
        SDL_Point point = monster.getTarget()->getPosition();
        
        _dest.x = point.x;
        _dest.y = point.y;
        
        SDL_Point curPos = monster.getPosition();
        SDL_Point newPos = curPos;
        
        if (!monster.isInDis(monster.getTarget(), monster.getPatrolDis()) ||
             monster.isInDis(monster.getTarget(), monster.getAttackDis()))
        {
            monster.changeState(new MonsterStandingState ());
        }
        else
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
            
            if (monster.getCounter() % Monster::ANI_FRAMES == 0) monster.frame++;
            if (monster.frame == Monster::ANI_FRAMES ) monster.frame = 0;
            monster.setPosition(newPos.x, newPos.y);
        }
    }
    else
    {
        monster.changeState(new MonsterStandingState ());
    }
}