//
//  Heroine.cpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 3/27/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#include "Heroine.hpp"
#include "HeroineMovingState.hpp"
#include "HeroineStandingState.hpp"

Heroine::Heroine () {}
Heroine::~Heroine() {delete _state;}

bool Heroine::init (std::string texture, int x, int y)
{
    bool bo = SESprite::init(texture, x, y);
    
    if (bo)
    {
        setHandleInput(true);
        
        _state = new HeroineStandingState ();
        
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
        
        return true;
    }
    
    return false;
}

int Heroine::getSpeed()
{
    return _speed;
}

int Heroine::getCounter()
{
    return (int)_counter;
}

void Heroine::changeState(HeroineState* state)
{
    delete _state;
    _state = state;
}

void Heroine::handleInput(SDL_Event e)
{
    HeroineState* state = _state->handleInput(*this, e);
    if (state != nullptr)
    {
        changeState(state);
    }
}

void Heroine::update ()
{
    _counter++;
    if (_counter > 100) _counter = 0;
    
    _state->update (*this);
}

Heroine* Heroine::create (std::string texture, int x, int y)
{
    Heroine *ge = new Heroine ();
    if (ge && ge->init(texture, x, y))
    {
        ge->autorelease();
        return ge;
    }
    else
    {
        //        CC_SAFE_DELETE(ge);
        return nullptr;
    }
}