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
class Heroine;

class Monster : public SESprite
{
private:
    MonsterState* _state;
    int _speed;
    long _counter;
    Heroine* _heroine;
    
public:
    static const int NEAR_DIS_X = 32;
    static const int NEAR_DIS_Y = 48;
    
    Monster ();
    ~Monster ();
    
    int getSpeed ();
    
    int getCounter ();
    
    bool isNearHeroine ();
    
    void changeState (MonsterState * state);
    
    static Monster* create (std::string texture, int x, int y);
    
    virtual bool init (std::string texture, int x, int y);
    
    virtual void update ();
};

#endif /* Monster_hpp */
