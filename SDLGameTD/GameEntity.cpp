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
}

bool GameEntity::isVisible()
{
    return _visible;
}

void GameEntity::addChild(GameEntity *child)
{
    children[children.size()] = child;
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