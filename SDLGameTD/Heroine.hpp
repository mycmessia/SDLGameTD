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
#include "MoveEntity.hpp"

USING_NS_SE;

class Monster;
class HeroineState;

class Heroine : public MoveEntity
{
private:
    SEGameEntity* _target;
    
    HeroineState* _state;
    float _speed;
    float _hp;
    float _attack;
    int _attackSpeed;
    int _attackDis;
    float _armor;
    
    long _counter;
    
public:
    static const int COUNTER_MAX = 100;
    static const int ANI_FRAMES = 3;        // ani sprite change every 4 frames
    
    Heroine ();
    ~Heroine ();
    
    SEGameEntity* getTarget ();
    void setTarget (SEGameEntity* ge);
    
    float getSpeed ();
    
    float getHp ();
    void setHp (float hp);
    
    float getAttack ();
    void setAttack (float attack);
    
    int getAttackDis ();
    void setAttackDis (int attackDis);
    
    int getAttackSpeed ();
    void setAttackSpeed (int as);
    
    float getArmor ();
    void setArmor (float armor);
    
    void attack (Monster* target);
    
    int getCounter ();
    
    virtual SDL_Rect* getClip();
    
    void changeState (HeroineState * state);
    
    static Heroine* create (std::string texture, SEPos pos, SEArea area, MoveEntityInfo info);
    
    virtual bool init (std::string texture, SEPos pos, SEArea area, MoveEntityInfo info);
    
    virtual void handleInput (SDL_Event e);
    
    virtual void update ();
};

#endif /* Heroine_hpp */
