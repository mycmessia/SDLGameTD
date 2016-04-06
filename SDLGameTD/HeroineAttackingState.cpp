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
#include "HeroineMovingState.hpp"
#include "HeroineAttackingState.hpp"

void HeroineAttackingState::handleInput (Heroine& heroine, SDL_Event e)
{
    if (heroine.isClickIn (e))
    {
        for (int i = 0; i < heroine.parent->children.size (); i++)
        {
            heroine.parent->children[i]->setFocus (false);
        }
        
        heroine.setFocus (true);
    }
    else
    {
        if (heroine.getFocus() && e.type == SDL_MOUSEBUTTONDOWN)
        {
            heroine.changeState(new HeroineMovingState (e.button.x, e.button.y));
        }
    }
}

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