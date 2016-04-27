//
//  MoveLabel.cpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 4/27/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#include "MoveLabel.hpp"

void MoveLabel::update()
{
    if (_duringFrame >= 0)
    {
        setPosition(getPosition().x, getPosition().y - _moveSpeed);
        _duringFrame--;
    }
    else
    {
        this->removeFromParent();
    }
}

bool MoveLabel::init(const std::string &message, const std::string &fontFile, SDL_Color color, int fontSize, SEPos pos)
{
    if (SELabel::init(message, fontFile, color, fontSize, pos))
    {
        _moveSpeed = 1;
        _duringFrame = 60;
        
        return true;
    }
    
    return false;
}

MoveLabel* MoveLabel::create(const std::string &message, const std::string &fontFile, SDL_Color color, int fontSize, SEPos pos)
{
    MoveLabel *ge = new MoveLabel ();
    if (ge && ge->init(message, fontFile, color, fontSize, pos))
    {
        ge->autoRelease();
        return ge;
    }
    else
    {
        SE_SAFE_DELETE(ge);
        return nullptr;
    }
}
