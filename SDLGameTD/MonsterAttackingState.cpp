//
//  MonsterAttackingState.cpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 4/6/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#include "Heroine.hpp"
#include "Monster.hpp"
#include "MonsterAttackingState.hpp"
#include "MonsterMovingState.hpp"
#include "MonsterStandingState.hpp"

void MonsterAttackingState::update(Monster &monster)
{
    Heroine* target = (Heroine*)monster.getTarget();
    
    if (target == nullptr) return;
    
    if (monster.isInDis(target, monster.getAttackDis()))
    {
        if (target->getHp () > 0.0f)
        {
            monster.attack(target);
        }
        else
        {
            //TODO monster change to die state
            target->removeFromParent();
            monster.setTarget(nullptr);
            monster.changeState(new MonsterStandingState ());
        }
    }
    else
    {
        monster.changeState(new MonsterMovingState ());
    }
}
