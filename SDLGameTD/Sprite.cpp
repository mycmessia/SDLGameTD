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

const SDL_Rect Sprite::getRect()
{
    Transform* trans = (Transform *)this->getComponent("Transform");
    
    int x = trans->x;
    int y = trans->y;
    
//    int w, h;
//    SDL_Texture* texture = this->getTexture();
//    SDL_QueryTexture(texture, nullptr, nullptr, &w, &h);
    
    return {x, y, _width, _height};
}

SDL_Rect* Sprite::getClip()
{
    switch (_moveDir)
    {
        case Left:
            return &leftClips[frame];
        case Right:
            return &rightClips[frame];
        case Up:
            return &upClips[frame];
        case Down:
            return &downClips[frame];
    }
}

int Sprite::getWidth() {return _width;}
int Sprite::getHeight() {return _height;}

MoveDir Sprite::getMoveDir () {return _moveDir;}
void Sprite::setMoveDir (MoveDir md) {_moveDir = md;}

bool Sprite::init(std::string texture, int x, int y)
{
    if(GameEntity::init())
    {
        _visible = true;
        
        _focus = false;
        
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