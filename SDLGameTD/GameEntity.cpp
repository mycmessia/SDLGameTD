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
    child->retain();
    children.push_back(child);
}

void GameEntity::addComponent(Component *compo)
{
    compo->retain();
    components.push_back(compo);
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
    
    std::cout << "Could not find component " << name << std::endl;
    return nullptr;
}

void GameEntity::removeComponent(std::string name)
{
    Component* compo = getComponent(name);
    
    if (compo)
    {
        compo->release();
    }
    else
    {
        std::cout << "Could not remove component " << name << std::endl;
    }
}

bool GameEntity::init()
{
    _referenceCount = 0;
    
    return true;
}

GameEntity* GameEntity::create()
{
    GameEntity *ge = new GameEntity ();
    if (ge && ge->init())
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