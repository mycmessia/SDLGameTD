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
    Monster* target = (Monster*)heroine.getTarget();
    
    if (target == nullptr) return;
    
    if (target->getHp () > 0.0f)
    {
        heroine.attack(target);
    }
    else
    {
        target->removeFromParent();
        // TODO set all heroine whose target == this target null
        
        for (int i = 0; i < heroine.parent->children.size (); i++)
        {
            if (((Heroine*)(heroine.parent->children[i]))->getTarget() == target)
            {
                ((Heroine*)(heroine.parent->children[i]))->setTarget(nullptr);
                ((Heroine*)(heroine.parent->children[i]))->changeState(new HeroineStandingState ());
            }
        }
//        heroine.setTarget(nullptr);
//        heroine.changeState(new HeroineStandingState ());
    }
}