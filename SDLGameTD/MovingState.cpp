//
//  MovingState.cpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 3/30/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#include "Heroine.hpp"
#include "StandingState.hpp"
#include "MovingState.hpp"

MovingState::MovingState (int x, int y)
{
    _dest.x = x;
    _dest.y = y;
}

HeroineState* MovingState::handleInput (Heroine& heroine, SDL_Event e)
{
    if (!heroine.isClickIn (e))
    {
        if (e.type == SDL_MOUSEBUTTONDOWN)
        {
            return new MovingState (e.button.x, e.button.y);
        }
    }
    
    return nullptr;
}

void MovingState::update(Heroine &heroine)
{
    SDL_Point curPos = heroine.getPosition();
    SDL_Point newPos = curPos;
    
    if (curPos.x != _dest.x || curPos.y != _dest.y)
    {
        if (curPos.x < _dest.x)
        {
            newPos.x += heroine.getSpeed();
        }
        else if (curPos.x > _dest.x)
        {
            newPos.x -= heroine.getSpeed();
        }
        else if (curPos.y < _dest.y)
        {
            newPos.y += heroine.getSpeed();
        }
        else if (curPos.y > _dest.y)
        {
            newPos.y -= heroine.getSpeed();
        }
        
        heroine.setPosition(newPos.x, newPos.y);
    }
    else
    {
        // arrive dest
        heroine.changeState(new StandingState ());
    }
}