//
//  StandingState.cpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 3/27/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#include "Heroine.hpp"
#include "MovingState.hpp"
#include "StandingState.hpp"

HeroineState* StandingState::handleInput (Heroine& heroine, SDL_Event e)
{
    if (heroine.isClickIn (e))
    {
        for (int i = 0; i < heroine.parent->children.size (); i++)
        {
            heroine.parent->children[i]->setFocus (false);
        }
        
//        std::cout << "hero focus" << std::endl;
        
        heroine.setFocus (true);
    }
    else
    {
        if (e.type == SDL_MOUSEBUTTONDOWN)
        {
            return new MovingState (e.button.x, e.button.y);
        }
    }
    
    return nullptr;
}

void StandingState::update (Heroine& heroine)
{
//    std::cout << "update standingState" << std::endl;
}