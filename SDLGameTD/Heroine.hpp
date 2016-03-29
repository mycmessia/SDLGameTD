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
#include "StandingState.hpp"

class Heroine : public Sprite
{
private:
    HeroineState* _state;
public:
    Heroine ();
    
    static Heroine* create (std::string texture, int x, int y);
    
    virtual bool init (std::string texture, int x, int y);
    
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
