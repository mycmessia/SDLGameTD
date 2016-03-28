//
//  Heroine.hpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 3/27/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#ifndef Heroine_hpp
#define Heroine_hpp

#include "HeroineState.hpp"

class Heroine : public GameEntity
{
private:
    HeroineState* _state;
public:
    virtual void handleInput (SDL_Event e)
    {
        _state->handleInput (*this, e);
    }
    
    virtual void update ()
    {
        _state->update (*this);
    }
};

#endif /* Heroine_hpp */
