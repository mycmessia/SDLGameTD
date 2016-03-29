//
//  Sprite.cpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 3/28/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#include "Sprite.hpp"

Sprite::Sprite (std::string texture, float x, float y)
{
    _visible = true;
    
    _texture = Window::LoadImage(texture);
    
    components.push_back(new Transform (x, y));
}

SDL_Texture* Sprite::getTexture()
{
    return _texture;
}