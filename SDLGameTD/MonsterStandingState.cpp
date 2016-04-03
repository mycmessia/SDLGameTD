//
//  MonsterStandingState.cpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 4/3/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#include "Monster.hpp"
#include "MonsterMovingState.hpp"
#include "MonsterStandingState.hpp"

MonsterState* MonsterStandingState::handleInput (Monster& monster, SDL_Event e)
{
    if (monster.isClickIn (e))
    {
        for (int i = 0; i < monster.parent->children.size (); i++)
        {
            monster.parent->children[i]->setFocus (false);
        }
        
        monster.setFocus (true);
    }
    else
    {
        if (monster.getFocus() && e.type == SDL_MOUSEBUTTONDOWN)
        {
            return new MonsterMovingState (e.button.x, e.button.y);
        }
    }
    
    return nullptr;
}

void MonsterStandingState::update (Monster& monster)
{
    //    std::cout << "update standingState" << std::endl;
}
