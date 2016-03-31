//
//  EventListener.cpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 3/31/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#include "EventListener.hpp"

// 类的静态成员变量必须先初始化再使用，虽然这个静态成员是私有的但是一样可以初始化
EventListener* EventListener::_instance = nullptr;

EventListener* EventListener::getInstance ()
{
    if (_instance == nullptr)
    {
        _instance = new EventListener ();
    }
    
    return _instance;
}

void EventListener::dispatchEvent(SDL_Event event)
{
    for (int i = 0; i < children.size(); i++)
    {
        children[i]->handleInput(event);
    }
}