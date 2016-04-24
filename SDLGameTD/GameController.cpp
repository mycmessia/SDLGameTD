//
//  GameController.cpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 4/24/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#include "GameController.hpp"

void GameController::onNotify (const SEGameEntity& entity, GAME_EVENT event)
{
    switch (event)
    {
        case MONSTER_DIE:
            // check win
            break;
        case HEROINE_DIE:
            // lose
            break;
            
        default:
            break;
    }
}