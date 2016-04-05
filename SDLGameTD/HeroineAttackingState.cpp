//
//  HeroineAttackingState.cpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 4/4/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#include "Heroine.hpp"
#include "Monster.hpp"
#include "HeroineStandingState.hpp"
#include "HeroineAttackingState.hpp"

void HeroineAttackingState::update(Heroine &heroine)
{
    Monster* targetMonster = (Monster*)heroine.getTarget();
    
    if (targetMonster == nullptr) return;
    
    if (targetMonster->getHp () > 0.0f)
    {
        heroine.attack(targetMonster);
    }
    else
    {
        //TODO monster change to die state
        targetMonster->removeFromParent();
        heroine.setTarget(nullptr);
        heroine.changeState(new HeroineStandingState ());
    }
}