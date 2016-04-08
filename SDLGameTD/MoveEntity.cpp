//
//  MoveEntity.cpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 4/8/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#include "MoveEntity.hpp"

SDL_Rect* MoveEntity::getClip()
{
    return nullptr;
}

MoveDir MoveEntity::getMoveDir () {return _moveDir;}
void MoveEntity::setMoveDir (MoveDir md) {_moveDir = md;}

bool MoveEntity::init(std::string texture, int x, int y)
{
    if(SEClipSprite::init(texture, x, y))
    {
        return true;
    }
    
    return false;
}