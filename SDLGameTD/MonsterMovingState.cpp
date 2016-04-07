//
//  MonsterMovingState.cpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 4/3/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#include "Monster.hpp"
#include "MonsterStandingState.hpp"
#include "MonsterAttackingState.hpp"
#include "MonsterMovingState.hpp"

MonsterMovingState::MonsterMovingState () {}

void MonsterMovingState::update(Monster &monster)
{
    if (monster.getTarget() == nullptr) return;
    
    if (monster.isInDis(monster.getTarget(), monster.getAttackDis()))
    {
        monster.changeState(new MonsterAttackingState ());
    }
    else
    {
        SE_Point point = monster.getTarget()->getPosition();
        
        _dest.x = point.x;
        _dest.y = point.y;
        
        SE_Point curPos = monster.getPosition();
        SE_Point newPos = curPos;
        
        float moveDisPerFrame = monster.getSpeed() / SEWindow::FPS;
        
        if (!monster.isInDis(monster.getTarget(), monster.getPatrolDis()))
        {
            monster.setTarget(nullptr);
            monster.changeState(new MonsterStandingState ());
        }
        else
        {
            if (curPos.x < _dest.x)
            {
                monster.setMoveDir(Right);
                newPos.x += moveDisPerFrame;
                if (newPos.x > _dest.x) newPos.x = _dest.x;
            }
            else if (curPos.x > _dest.x)
            {
                monster.setMoveDir(Left);
                newPos.x -= moveDisPerFrame;
                if (newPos.x < _dest.x) newPos.x = _dest.x;
            }
            else if (curPos.y < _dest.y)
            {
                monster.setMoveDir(Down);
                newPos.y += moveDisPerFrame;
                if (newPos.y > _dest.y) newPos.y = _dest.y;
            }
            else if (curPos.y > _dest.y)
            {
                monster.setMoveDir(Up);
                newPos.y -= moveDisPerFrame;
                if (newPos.y < _dest.y) newPos.y = _dest.y;
            }
            
            if (monster.getCounter() % Monster::ANI_FRAMES == 0) monster.frame++;
            if (monster.frame == Monster::ANI_FRAMES ) monster.frame = 0;
            monster.setPosition(newPos.x, newPos.y);
        }
    }
}