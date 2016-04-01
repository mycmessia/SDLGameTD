//
//  StandingState.cpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 3/27/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#include "Heroine.hpp"
#include "HeroineMovingState.hpp"
#include "HeroineStandingState.hpp"

HeroineState* HeroineStandingState::handleInput (Heroine& heroine, SDL_Event e)
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
            return new HeroineMovingState (e.button.x, e.button.y);
        }
    }
    
    return nullptr;
}

void HeroineStandingState::update (Heroine& heroine)
{
//    std::cout << "update standingState" << std::endl;
}