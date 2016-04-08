//
//  Sprite.cpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 3/28/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#include "SESprite.hpp"

USING_NS_SE;

SDL_Texture* SESprite::getTexture()
{
    return _texture;
}

const SDL_Rect SESprite::getRect()
{
    SETransform* trans = (SETransform *)this->getComponent("Transform");
    
    int x = (int)(trans->x);
    int y = (int)(trans->y);
    
    return {x, y, _width, _height};
}

bool SESprite::isClickIn(SDL_Event e)
{
    SDL_Rect rect = this->getRect();
    
    if (e.type == SDL_MOUSEBUTTONDOWN)
    {
        if (e.button.x >= rect.x && e.button.x <= rect.x + rect.w &&
            e.button.y >= rect.y && e.button.y <= rect.y + rect.h)
        {
            return true;
        }
    }
    
    return false;
}

//SDL_Rect* SESprite::getClip()
//{
//    return nullptr;
////    switch (_moveDir)
////    {
////        case Left:
////            return &leftClips[frame];
////        case Right:
////            return &rightClips[frame];
////        case Up:
////            return &upClips[frame];
////        case Down:
////            return &downClips[frame];
////    }
//}
bool SESprite::isUseClip() {return _useClip;};

int SESprite::getWidth() {return _width;}
int SESprite::getHeight() {return _height;}

bool SESprite::init(std::string texture, int x, int y)
{
    if(SEGameEntity::init())
    {
        _visible = true;
        
        _useClip = false;
        
        _focus = false;
        
        _texture = SEWindow::LoadImage(texture);
        
        setPosition(x, y);
        
        return true;
    }
    
    return false;
}

SESprite* SESprite::create(std::string texture, int x, int y)
{
    SESprite *ge = new SESprite ();
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