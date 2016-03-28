//
//  GameEntity.hpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 3/24/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#ifndef GameEntity_hpp
#define GameEntity_hpp

#include <vector>
#include "Window.hpp"

class GameEntity
{
public:
    GameEntity* parent;
    std::vector<GameEntity*> children;
    std::vector<Component*> components;
    
    void addChild (GameEntity* child);
};

#endif /* GameEntity_hpp */
