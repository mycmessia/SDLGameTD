//
//  Monster.cpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 4/3/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#include "Heroine.hpp"
#include "Monster.hpp"
#include "MonsterState.hpp"
#include "MonsterStandingState.hpp"

Monster::Monster () {}
Monster::~Monster() {SE_SAFE_DELETE(_state);}

bool Monster::init (std::string texture, int x, int y)
{
    bool bo = SESprite::init(texture, x, y);
    
    if (bo)
    {
        _state = new MonsterStandingState ();
        
        _width = 32;
        
        _height = 48;
        
        _moveDir = Down;
        
        _speed = 1;
        
        _hp = 20;
        
        _attack = 16;
        
        _attackSpeed = 2;
        
        _armor = 8;
        
        _attackDis = 48;
        
        _patrolDis = 96;
        
        frame = 0;
        
        for (int i = 0; i < 4; i++)
        {
            downClips[i] = {i * _width, 0, _width, _height};
            leftClips[i] = {i * _width, _height, _width, _height};
            rightClips[i] = {i * _width, 2 * _height, _width, _height};
            upClips[i] = {i * _width, 3 * _height, _width, _height};
        }
        
        _counter = 0;
        
        _target = nullptr;
        
        return true;
    }
    
    return false;
}

int Monster::getSpeed() {return _speed;}

int Monster::getPatrolDis () {return _patrolDis;}
void Monster::setPatrolDis (int pd) {_patrolDis = pd;}

int Monster::getAttackDis () {return _attackDis;}
void Monster::setAttackDis (int attackDis) {_attackDis = attackDis;}

float Monster::getHp () {return _hp;}
void Monster::setHp (float hp) {_hp = hp;}

float Monster::getAttack () {return _attack;}
void Monster::setAttack (float attack) {_attack = attack;}

float Monster::getArmor () {return _armor;}
void Monster::setArmor (float armor) {_armor = armor;}

int Monster::getCounter() {return _counter;}

bool Monster::isInDis(SEGameEntity* ge, int dis)
{
    SE_Point gePos = ge->getPosition();
    SE_Point thisPos = getPosition();
    
    if ((gePos.x - thisPos.x) * (gePos.x - thisPos.x) + (gePos.y - thisPos.y) * (gePos.y - thisPos.y) <= dis * dis)
    {
        return true;
    }
    
    return false;
}

SEGameEntity* Monster::getTarget ()
{
    return _target;
}

void Monster::setTarget (SEGameEntity* target)
{
    _target = target;
}

void Monster::attack(Heroine* target)
{
    if (getCounter() % (SEWindow::FPS / _attackSpeed) == 0)
    {
        if (this->getAttack() > target->getArmor())
        {
            target->setHp(target->getHp() - (this->getAttack() - target->getArmor()));
        }
        else
        {
            std::cout << "your attack is equal or lower than target's armor" << std::endl;
        }
    }
}

void Monster::changeState(MonsterState* state)
{
    delete _state;
    _state = state;
}

void Monster::update ()
{
    _counter++;
    if (_counter >= Monster::COUNTER_MAX) _counter = 0;
    
    _state->update (*this);
}

Monster* Monster::create (std::string texture, int x, int y)
{
    Monster *ge = new Monster ();
    if (ge && ge->init(texture, x, y))
    {
        ge->autoRelease();
        return ge;
    }
    else
    {
        SE_SAFE_DELETE(ge);
        return nullptr;
    }
}