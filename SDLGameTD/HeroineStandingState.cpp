//
//  StandingState.cpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 3/27/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#include "TagManager.hpp"
#include "Heroine.hpp"
#include "HeroineMovingState.hpp"
#include "HeroineStandingState.hpp"
#include "HeroineAttackingState.hpp"

void HeroineStandingState::handleInput (Heroine& heroine, SDL_Event e)
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

void HeroineStandingState::update (Heroine& heroine)
{
    if (heroine.getTarget())
    {
        std::cout << "change to attack" << std::endl;
        heroine.changeState(new HeroineAttackingState ());
    }
    else
    {
        SEGameEntity* camp1 = SEDirector::getInstance()->getCurrentScene()->getChildByTag(TagManager::CAMP_1);
        for (int i = 0; i < camp1->children.size(); i++)
        {
            if (heroine.isInDis(camp1->children[i], heroine.getAttackDis()))
            {
                heroine.setTarget(camp1->children[i]);
                break;
            }
        }
    }
}