//
//  MovingState.cpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 3/30/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#include "Heroine.hpp"
#include "HeroineStandingState.hpp"
#include "HeroineMovingState.hpp"

HeroineMovingState::HeroineMovingState (int x, int y)
{
    _dest.x = x;
    _dest.y = y;
}

HeroineState* HeroineMovingState::handleInput (Heroine& heroine, SDL_Event e)
{
    if (!heroine.isClickIn (e))
    {
        if (e.type == SDL_MOUSEBUTTONDOWN)
        {
            _dest.x = e.button.x;
            _dest.y = e.button.y;
        }
    }
    
    return nullptr;
}

void HeroineMovingState::update(Heroine &heroine)
{
    SDL_Point curPos = heroine.getPosition();
    SDL_Point newPos = curPos;
    
    if (curPos.x != _dest.x || curPos.y != _dest.y)
    {
        if (curPos.x < _dest.x)
        {
            heroine.setMoveDir(Right);
            newPos.x += heroine.getSpeed();
        }
        else if (curPos.x > _dest.x)
        {
            heroine.setMoveDir(Left);
            newPos.x -= heroine.getSpeed();
        }
        else if (curPos.y < _dest.y)
        {
            heroine.setMoveDir(Down);
            newPos.y += heroine.getSpeed();
        }
        else if (curPos.y > _dest.y)
        {
            heroine.setMoveDir(Up);
            newPos.y -= heroine.getSpeed();
        }
        
        if (heroine.getCounter() % 4 == 0) heroine.frame++;
        if (heroine.frame == 4) heroine.frame = 0;
        heroine.setPosition(newPos.x, newPos.y);
    }
    else
    {
        // arrive dest
        heroine.changeState(new HeroineStandingState ());
    }
}