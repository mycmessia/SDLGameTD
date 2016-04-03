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
        
        _speed = 1;
        
        _width = 32;
        
        _height = 48;
        
        _moveDir = Down;
        
        frame = 0;
        
        for (int i = 0; i < 4; i++)
        {
            downClips[i] = {i * _width, 0, _width, _height};
            leftClips[i] = {i * _width, _height, _width, _height};
            rightClips[i] = {i * _width, 2 * _height, _width, _height};
            upClips[i] = {i * _width, 3 * _height, _width, _height};
        }
        
        _counter = SEWindow::GetCurrentTime();
        
        _heroine = (Heroine*)SEDirector::getInstance()->getCurrentScene()->getChildByTag(1);
        
        return true;
    }
    
    return false;
}

int Monster::getSpeed()
{
    return _speed;
}

int Monster::getCounter()
{
    return (int)_counter;
}

bool Monster::isNearHeroine()
{
    SDL_Point heroPos = _heroine->getPosition();
    SDL_Point monsterPos = getPosition();
    
    if (abs(heroPos.x - monsterPos.x) <= Monster::NEAR_DIS_X &&
        abs(heroPos.y - monsterPos.y) <= Monster::NEAR_DIS_Y)
    {
        return true;
    }
    
    return false;
}

void Monster::changeState(MonsterState* state)
{
    delete _state;
    _state = state;
}

void Monster::update ()
{
    _counter++;
    if (_counter > 100) _counter = 0;
    
    _state->update (*this);
}

Monster* Monster::create (std::string texture, int x, int y)
{
    Monster *ge = new Monster ();
    if (ge && ge->init(texture, x, y))
    {
        ge->autorelease();
        return ge;
    }
    else
    {
        SE_SAFE_DELETE(ge);
        return nullptr;
    }
}