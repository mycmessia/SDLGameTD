//
//  Sprite.cpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 3/28/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#include "Sprite.hpp"

SDL_Texture* Sprite::getTexture()
{
    return _texture;
}

bool Sprite::init(std::string texture, int x, int y)
{
    if(GameEntity::init())
    {
        _visible = true;
        
        _texture = Window::LoadImage(texture);
        
        addComponent(Transform::create (x, y));
        
        return true;
    }
    
    return false;
}

Sprite* Sprite::create(std::string texture, int x, int y)
{
    Sprite *ge = new Sprite ();
    if (ge && ge->init(texture, x, y))
    {
        //        ge->autorelease();
        return ge;
    }
    else
    {
        delete ge;
        return nullptr;
    }
}