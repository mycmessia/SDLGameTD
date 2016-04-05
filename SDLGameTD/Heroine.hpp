//
//  Heroine.hpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 3/27/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#ifndef Heroine_hpp
#define Heroine_hpp

#include "SimpleEngine.h"

USING_NS_SE;

class Monster;
class HeroineState;

class Heroine : public SESprite
{
private:
    SEGameEntity* _target;
    
    HeroineState* _state;
    int _speed;
    float _hp;
    float _attack;
    int _attackSpeed;
    float _armor;
    
    long _counter;
    
public:
    static const int NEAR_DIS_X = 32;
    static const int NEAR_DIS_Y = 48;
    
    Heroine ();
    ~Heroine ();
    
    bool isNear (SEGameEntity* ge);
    SEGameEntity* getTarget ();
    void setTarget (SEGameEntity* ge);
    
    int getSpeed ();
    float getHp ();
    void setHp (float hp);
    float getAttack ();
    void setAttack (float attack);
    int getAttackSpeed ();
    void setAttackSpeed (int as);
    float getArmor ();
    void setArmor (float armor);
    
    void attack (Monster* target);
    
    int getCounter ();
    
    void changeState (HeroineState * state);
    
    static Heroine* create (std::string texture, int x, int y);
    
    virtual bool init (std::string texture, int x, int y);
    
    virtual void handleInput (SDL_Event e);
    
    virtual void update ();
};

#endif /* Heroine_hpp */
