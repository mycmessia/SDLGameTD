//
//  EventListener.cpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 3/31/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#include "SEEventListener.hpp"
#include "SESprite.hpp"

USING_NS_SE;

// 类的静态成员变量必须先初始化再使用，虽然这个静态成员是私有的但是一样可以初始化
SEEventListener* SEEventListener::_instance = nullptr;

SEEventListener* SEEventListener::getInstance ()
{
    if (_instance == nullptr)
    {
        _instance = new SEEventListener ();
    }
    
    return _instance;
}

void SEEventListener::dispatchEvent(SDL_Event event)
{
    for (int i = 0; i < _listerners.size(); i++)
    {
        _listerners[i]->handleInput(event);
            
        if (_listerners[i]->isClickIn(event) && _listerners[i]->getSwallowEvent())
        {
//            std::cout << "break event" << std::endl;
            break;
        }
    }
}

void SEEventListener::addListener(SEGameEntity* ge)
{
    if (ge->isUI())
    {
        _listerners.insert(_listerners.begin(), ge);
    }
    else
    {
        _listerners.push_back(ge);
    }
}

void SEEventListener::removeListener(SEGameEntity* ge)
{
    for (int i = 0; i < _listerners.size(); i++)
    {
        if (_listerners[i] == ge)
        {
            _listerners[i] = nullptr;
            _listerners.erase(_listerners.begin() + i);
            break;
        }
    }
}

