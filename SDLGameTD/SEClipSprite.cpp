//
//  SEClipSprite.cpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 4/8/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#include "SEClipSprite.hpp"

USING_NS_SE;

SDL_Rect* SEClipSprite::getClip()
{
    return nullptr;
}

bool SEClipSprite::init(std::string texture, int x, int y)
{
    if(SESprite::init(texture, x, y))
    {
        _useClip = true;
        
        return true;
    }
    
    return false;
}

SEClipSprite* SEClipSprite::create(std::string texture, int x, int y)
{
    SEClipSprite *ge = new SEClipSprite ();
    if (ge && ge->init(texture, x, y))
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