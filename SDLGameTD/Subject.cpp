//
//  Subject.cpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 4/24/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#include "Subject.hpp"

USING_NS_SE;


Subject* Subject::_instance = nullptr;

Subject* Subject::getInstance ()
{
    if (_instance == nullptr)
    {
        _instance = new Subject ();
    }
    
    return _instance;
}

Subject::~Subject()
{
    for (int i = 0; i < _obsVector.size(); i++)
    {
        SE_SAFE_DELETE(_obsVector[i]);
    }
    
    SE_SAFE_DELETE(_instance);
}

void Subject::addObserver(Observer *observer)
{
    _obsVector.push_back(observer);
}

void Subject::removeObserver(Observer* observer)
{
    for (int i = 0; i < _obsVector.size(); i++)
    {
        if (_obsVector[i] == observer)
        {
            SE_SAFE_DELETE(_obsVector[i]);
            _obsVector.erase(_obsVector.begin() + i);
            break;
        }
    }
}

void Subject::notify(SEGameEntity& entity, GAME_EVENT event)
{
    for (int i = 0; i < _obsVector.size(); i++)
    {
        _obsVector[i]->onNotify(entity, event);
    }
}