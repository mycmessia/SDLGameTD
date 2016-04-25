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

void HeroineMovingState::handleInput (Heroine& heroine, SDL_Event e)
{
    if (!heroine.isClickIn (e) && heroine.getFocus())
    {
        if (e.type == SDL_MOUSEBUTTONUP)
        {
            _dest.x = e.button.x;
            _dest.y = e.button.y;
        }
    }
}

void HeroineMovingState::update (Heroine &heroine)
{
    SE_Point curPos = heroine.getPosition();
    SE_Point newPos = curPos;
    float moveDisPerFrame = heroine.getSpeed() / SEWindow::FPS;;
    
    if (!heroine.isInDis(_dest, 1))
    {
        if (curPos.x < _dest.x)
        {
            heroine.setMoveDir(Right);
            newPos.x += moveDisPerFrame;
            if (newPos.x > _dest.x) newPos.x = _dest.x;
        }
        else if (curPos.x > _dest.x)
        {
            heroine.setMoveDir(Left);
            newPos.x -= moveDisPerFrame;
            if (newPos.x < _dest.x) newPos.x = _dest.x;
        }
        else if (curPos.y < _dest.y)
        {
            heroine.setMoveDir(Down);
            newPos.y += moveDisPerFrame;
            if (newPos.y > _dest.y) newPos.y = _dest.y;
        }
        else if (curPos.y > _dest.y)
        {
            heroine.setMoveDir(Up);
            newPos.y -= moveDisPerFrame;
            if (newPos.y < _dest.y) newPos.y = _dest.y;
        }
        
        if (heroine.getCounter() % Heroine::ANI_FRAMES == 0) heroine.frame++;
        if (heroine.frame == Heroine::ANI_FRAMES) heroine.frame = 0;
        heroine.setPosition(newPos.x, newPos.y);
    }
    else
    {
        // arrive dest
        heroine.changeState(new HeroineStandingState ());
    }
}