//
//  Monster.hpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 4/3/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#ifndef Monster_hpp
#define Monster_hpp

#include "SimpleEngine.h"

USING_NS_SE;

class MonsterState;

class Monster : public SESprite
{
private:
    MonsterState* _state;
    int _speed;
    
    long _counter;
    
public:
    
    Monster ();
    ~Monster ();
    
    int getSpeed ();
    
    int getCounter ();
    
    void changeState (MonsterState * state);
    
    static Monster* create (std::string texture, int x, int y);
    
    virtual bool init (std::string texture, int x, int y);
    
    virtual void handleInput (SDL_Event e);
    
    virtual void update ();
};

#endif /* Monster_hpp */
