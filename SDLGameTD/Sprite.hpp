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
#include "Transform.hpp"

class Sprite : public GameEntity
{
private:
    SDL_Texture* _texture;
    
public:
    Sprite ();
    
    SDL_Texture* getTexture ();
    
    static Sprite* create (std::string texture, int x, int y);
    
    virtual bool init (std::string texture, int x, int y);
    
    virtual void handleInput (SDL_Event e) {};
    
    virtual void update () {};
};

#endif /* Sprite_hpp */
