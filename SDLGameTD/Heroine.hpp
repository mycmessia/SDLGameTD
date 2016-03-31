//
//  Heroine.hpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 3/27/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#ifndef Heroine_hpp
#define Heroine_hpp

#include "Sprite.hpp"

class HeroineState;

class Heroine : public Sprite
{
private:
    HeroineState* _state;
    
    int _speed;
    
    long _counter;
    
public:
    Heroine ();
    ~Heroine ();
    
    int getSpeed ();
    
    void changeState (HeroineState * state);
    
    bool isClickIn (SDL_Event e);
    
    static Heroine* create (std::string texture, int x, int y);
    
    virtual bool init (std::string texture, int x, int y);
    
    virtual void handleInput (SDL_Event e);
    
    virtual void update ();
};

#endif /* Heroine_hpp */
