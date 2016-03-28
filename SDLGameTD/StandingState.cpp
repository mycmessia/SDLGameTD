//
//  StandingState.cpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 3/27/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#include "StandingState.hpp"

void StandingState::handleInput (GameEntity& heroine, SDL_Event e)
{
    if (e.type == SDL_KEYDOWN)
    {
        switch (e.key.keysym.sym)
        {
            case SDLK_s:
                std::cout << "handleInput standingState" << std::endl;
                break;
        }
    }
}

void StandingState::update (GameEntity& heroine)
{
    std::cout << "update standingState" << std::endl;
}