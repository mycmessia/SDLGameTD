//
//  Monster.cpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 4/3/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#include "TagManager.hpp"
#include "Heroine.hpp"
#include "Monster.hpp"
#include "MonsterState.hpp"
#include "MonsterMovingState.hpp"
#include "MonsterAttackingState.hpp"

Monster::Monster () {}
Monster::~Monster() {SE_SAFE_DELETE(_state);}

bool Monster::init (std::string texture, int x, int y)
{
    bool bo = MoveEntity::init(texture, x, y);
    
    if (bo)
    {
        _state = new MonsterMovingState ();
        
        movePath.push_back({240, 200});
        movePath.push_back({240, 350});
        movePath.push_back({40, 350});
        movePath.push_back({40, 500});
        movePath.push_back({360, 500});
//        movePath.push_back({480, 320});
        
        movePathCounter = 0;
        
        _width = 34;
        
        _height = 34;
        
        _moveDir = Down;
        
        _speed = 120;
        
        _hp = 20;
        
        _attack = 16;
        
        _attackSpeed = 2;
        
        _armor = 8;
        
        _attackDis = 48;
        
        _patrolDis = 96;
        
        frame = 0;
        
        for (int i = 0; i < 3; i++)
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

float Monster::getSpeed() {return _speed;}

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

SEGameEntity* Monster::getTarget ()
{
    return _target;
}

void Monster::setTarget (SEGameEntity* target)
{
    _target = target;
}

void Monster::findTarget()
{
    SEGameEntity* camp2 = SEDirector::getInstance()->getCurrentScene()->getChildByTag(TagManager::CAMP_2);
    for (int i = 0; i < camp2->children.size(); i++)
    {
        if (isInDis(camp2->children[i], getAttackDis()))
        {
            setTarget(camp2->children[i]);
            changeState(new MonsterAttackingState());
            break;
        }
        
        if (isInDis(camp2->children[i], getPatrolDis()))
        {
            setTarget(camp2->children[i]);
            changeState(new MonsterMovingState());
            break;
        }
    }
}

SDL_Rect* Monster::getClip()
{
    switch (_moveDir)
    {
        case Left:
            return &leftClips[frame];
        case Right:
            return &rightClips[frame];
        case Up:
            return &upClips[frame];
        case Down:
            return &downClips[frame];
    }
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