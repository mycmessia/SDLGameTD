//
//  Director.cpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 3/29/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#include "Director.hpp"

Director::Director ()
{
    _currentScene = new GameEntity ();
}

Director* Director::getInstance()
{
    if (_instance == nullptr)
    {
        _instance = new Director ();
    }
    
    return _instance;
}

GameEntity* Director::getCurrentScene()
{
    return _currentScene;
}