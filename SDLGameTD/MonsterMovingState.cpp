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
#include "Subject.hpp"

MonsterMovingState::MonsterMovingState () {}

void MonsterMovingState::move(Monster &monster)
{
    SE_Point curPos = monster.getPosition();
    SE_Point newPos = curPos;
    
    float moveDisPerFrame = monster.getSpeed() / SEWindow::FPS;
    
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

void MonsterMovingState::update(Monster &monster)
{
    monster.findTarget();
    
    if (monster.getTarget() == nullptr)
    {
        _dest.x = monster.movePath[monster.movePathCounter].x;
        _dest.y = monster.movePath[monster.movePathCounter].y;
        
        if (monster.isInDis(_dest, 1))
        {
            if (monster.movePathCounter < monster.movePath.size() - 1)
            {
                monster.movePathCounter++;
            }
            else
            {
                Subject::getInstance()->notify(monster, MONSTER_DIE);
                
                monster.removeFromParent();
            }
        }
        else
        {
            move (monster);
        }
    }
    else
    {
        if (monster.isInDis(monster.getTarget(), monster.getAttackDis()))
        {
            monster.changeState(new MonsterAttackingState ());
        }
        else if (!monster.isInDis(monster.getTarget(), monster.getPatrolDis()))
        {
            monster.setTarget(nullptr);
        }
        else
        {
            SE_Point point = monster.getTarget()->getPosition();
            
            _dest.x = point.x;
            _dest.y = point.y;
            
            move (monster);
        }
    }
}