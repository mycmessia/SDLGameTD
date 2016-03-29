//
//  GameEntity.cpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 3/24/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#include "GameEntity.hpp"

GameEntity::GameEntity ()
{
    _visible = false;
    _handleInput = false;
}

bool GameEntity::isVisible ()
{
    return _visible;
}

bool GameEntity::isHandleInput ()
{
    return _handleInput;
}

void GameEntity::addChild(GameEntity *child)
{
    children.push_back(child);
}

Component* GameEntity::getComponent(std::string name)
{
    for (int i = 0; i < components.size(); i++)
    {
        if (components[i]->title == name)
        {
            return components[i];
        }
    }
    
    std::cout<< "Could not find component " << name << std::endl;
    return components[0];
}

bool GameEntity::init()
{
    return true;
}

GameEntity* GameEntity::create()
{
    GameEntity *ge = new GameEntity ();
    if (ge && ge->init())
    {
//        ge->autorelease();
        return ge;
    }
    else
    {
//        CC_SAFE_DELETE(ge);
        return nullptr;
    }
}