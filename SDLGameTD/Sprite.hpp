//
//  Sprite.hpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 3/28/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#ifndef Sprite_hpp
#define Sprite_hpp

#include "GameEntity.hpp"

class Sprite : public GameEntity
{
public:
    Sprite (std::string texture, float x, float y);
    
    SDL_Texture* getTexture ();
    
private:
    SDL_Texture* _texture;
};

#endif /* Sprite_hpp */
