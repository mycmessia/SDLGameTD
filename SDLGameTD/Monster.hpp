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
    SEGameEntity* _target;
    
    MonsterState* _state;
    float _speed;
    float _hp;
    float _attack;
    int _attackSpeed;
    int _attackDis;
    float _armor;
    int _patrolDis;                         // 玩家达到多少距离开始追击
    
    int _counter;
    
public:
    static const int COUNTER_MAX = 100;
    static const int ANI_FRAMES = 4;        // ani sprite change every 4 frames
    
    Monster ();
    ~Monster ();
    
    float getSpeed ();
    
    int getPatrolDis ();
    void setPatrolDis (int pd);
    
    float getHp ();
    void setHp (float hp);
    
    float getAttack ();
    void setAttack (float attack);
    
    int getAttackDis ();
    void setAttackDis (int attackDis);
    
    float getArmor ();
    void setArmor (float armor);
    
    int getCounter ();
    
    SEGameEntity* getTarget ();
    void setTarget (SEGameEntity* target);
    
    void attack (Heroine* target);
    
    void changeState (MonsterState* state);
    
    static Monster* create (std::string texture, int x, int y);
    
    virtual bool init (std::string texture, int x, int y);
    
    virtual void update ();
};

#endif /* Monster_hpp */
