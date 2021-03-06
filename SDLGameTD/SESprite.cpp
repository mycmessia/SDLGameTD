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
    SE_Point destPos = {getPosition().x, getPosition().y};
    
    SEGameEntity* posParent = this->parent;
    while (posParent)
    {
        destPos = {destPos.x + posParent->getPosition().x, destPos.y + posParent->getPosition().y};
        posParent = posParent->parent;
    }
    
    SDL_Rect worldRect = {
        (int)(destPos.x),
        (int)(destPos.y),
        _width,
        _height
    };
    
    return worldRect;
}

bool SESprite::isClickIn(SDL_Event e)
{
    SDL_Rect rect = this->getRect();
    
    if (e.type == SDL_MOUSEBUTTONUP)
    {
        if (e.button.x >= rect.x && e.button.x <= rect.x + rect.w &&
            e.button.y >= rect.y && e.button.y <= rect.y + rect.h)
        {
            return true;
        }
    }
    
    return false;
}

int SESprite::getWidth() {return _width;}
int SESprite::getHeight() {return _height;}

void SESprite::draw()
{
    if (isVisible())
    {
        SEWindow::Draw(getTexture(), getRect());
    }
}

bool SESprite::initWithSharedTexture(SDL_Texture* sharedTexture, int x, int y)
{
    if(SEGameEntity::init())
    {
        _visible = true;
        
        _focus = false;
        
        _texture = sharedTexture;
        
        setPosition(x, y);
        
        return true;
    }
    
    return false;
}

bool SESprite::init(std::string texture, int x, int y)
{
    if(SEGameEntity::init())
    {
        _visible = true;
        
        _focus = false;
        
        _texture = SEWindow::LoadImage(texture);
        
        setPosition(x, y);
        
        return true;
    }
    
    return false;
}

bool SESprite::init(std::string texture, int x, int y, int width, int height)
{
    if(SEGameEntity::init())
    {
        _visible = true;
        
        _focus = false;
        
        _width = width;
        
        _height = height;
        
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

SESprite* SESprite::create(std::string texture, int x, int y, int width, int height)
{
    SESprite *ge = new SESprite ();
    if (ge && ge->init(texture, x, y, width, height))
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