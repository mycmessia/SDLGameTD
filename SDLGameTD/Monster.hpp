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
#include "MoveEntity.hpp"

USING_NS_SE;

class MonsterState;
class Heroine;

class Monster : public MoveEntity
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
    static const int ANI_FRAMES = 3;        // ani sprite change every 4 frames
    
    std::vector<SE_Point> movePath;
    int movePathCounter;
    
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
    
    virtual SDL_Rect* getClip();
    
    SEGameEntity* getTarget ();
    void setTarget (SEGameEntity* target);
    void findTarget ();
    
    void attack (Heroine* target);
    
    void changeState (MonsterState* state);
    
    static Monster* create (std::string texture, SEPos pos, SEArea area, MoveEntityInfo info);
    
    virtual bool init (std::string texture, SEPos pos, SEArea area, MoveEntityInfo info);
    
    virtual void update ();
};

#endif /* Monster_hpp */
