//
//  Heroine.cpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 3/27/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#include "Monster.hpp"
#include "Heroine.hpp"
#include "HeroineMovingState.hpp"
#include "HeroineStandingState.hpp"
#include "MoveLabel.hpp"
#include "Config.hpp"

Heroine::Heroine () {}
Heroine::~Heroine() {delete _state;}

bool Heroine::init (std::string texture, SEPos pos, SEArea area, MoveEntityInfo info)
{
    bool bo = MoveEntity::init(texture, pos.x, pos.y);
    
    if (bo)
    {
        _state = new HeroineStandingState ();
        
        _speed = info.speed;
        
        _hp = info.hp;
        
        _attack = info.attack;
        
        _attackDis = info.attackDis;
        
        _attackSpeed = info.attackSpeed;
        
        _armor = info.armor;
        
        _width = area.width;
        
        _height = area.height;
        
        _moveDir = Down;
        
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
        
        setHandleInput(true);
        
        setSwallowEvent(true);
        
        return true;
    }
    
    return false;
}

SEGameEntity* Heroine::getTarget () {return _target;}
void Heroine::setTarget (SEGameEntity* ge) {_target = ge;}

float Heroine::getSpeed() {return _speed;}

float Heroine::getHp () {return _hp;}
void Heroine::setHp (float hp) {_hp = hp;}

float Heroine::getAttack () {return _attack;}
void Heroine::setAttack (float attack) {_attack = attack;}

int Heroine::getAttackDis () {return _attackDis;}
void Heroine::setAttackDis (int attackDis) {_attackDis = attackDis;}

int Heroine::getAttackSpeed () {return _attackSpeed;}
void Heroine::setAttackSpeed (int as) {_attackSpeed = as;}

float Heroine::getArmor () {return _armor;}
void Heroine::setArmor (float armor) {_armor = armor;}

void Heroine::attack(Monster* target)
{
    if (getCounter() % (SEWindow::FPS / _attackSpeed) == 0)
    {
        if (this->getAttack() > target->getArmor())
        {
            int loseHP = this->getAttack() - target->getArmor();
            SEPos labelPos = {target->getPosition().x + target->getWidth() / 3, target->getPosition().y};
            
            MoveLabel* loseHPLabel = MoveLabel::create(
                std::to_string(loseHP),
                Config::DEFAULT_FONT,
                {255, 255,255, 0}, 26, labelPos);
            
            SEDirector::getInstance()->getCurrentScene()->addChild(loseHPLabel);
            
            target->setHp(target->getHp() - loseHP);
        }
        else
        {
            std::cout << "your attack is lower than target's armor" << std::endl;
        }
    }
}

int Heroine::getCounter(){return (int)_counter;}

void Heroine::changeState(HeroineState* state)
{
    delete _state;
    _state = state;
}

SDL_Rect* Heroine::getClip()
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

void Heroine::handleInput(SDL_Event e)
{
    _state->handleInput(*this, e);
}

void Heroine::update ()
{
    _counter++;
    if (_counter > Heroine::COUNTER_MAX) _counter = 0;
    
    _state->update (*this);
}

Heroine* Heroine::create (std::string texture, SEPos pos, SEArea area, MoveEntityInfo info)
{
    Heroine *ge = new Heroine ();
    if (ge && ge->init(texture, pos, area, info))
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