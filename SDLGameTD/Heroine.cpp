//
//  Heroine.cpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 3/27/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#include "Heroine.hpp"
#include "StandingState.hpp"
#include "MovingState.hpp"

Heroine::Heroine () {}
Heroine::~Heroine() {delete _state;}

bool Heroine::init (std::string texture, int x, int y)
{
    bool bo = Sprite::init(texture, x, y);
    
    if (bo)
    {
        setHandleInput(true);
        
        _state = new StandingState ();
        
        _speed = 1;
    
        _counter = Window::GetCurrentTime();
        
        return true;
    }
    
    return false;
}

int Heroine::getSpeed()
{
    return _speed;
}

void Heroine::changeState(HeroineState* state)
{
    delete _state;
    _state = state;
}

void Heroine::handleInput(SDL_Event e)
{
//    std::cout << "handle Input Heroine" << Window::GetCurrentTime() - _counter << std::endl;
//    
//    _counter = Window::GetCurrentTime();
    
    HeroineState* state = _state->handleInput(*this, e);
    if (state != nullptr)
    {
//        std::cout << "change state" << std::endl;
//        std::cout << Window::GetCurrentTime() << std::endl;
        changeState(state);
    }
}

void Heroine::update ()
{
    _state->update (*this);
}

bool Heroine::isClickIn(SDL_Event e)
{
    SDL_Rect rect = this->getRect();
    
    if (e.type == SDL_MOUSEBUTTONDOWN)
    {
        if (e.button.x >= rect.x && e.button.x <= rect.x + rect.w &&
            e.button.y >= rect.y && e.button.y <= rect.y + rect.h)
        {
            return true;
        }
    }
    
    return false;
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