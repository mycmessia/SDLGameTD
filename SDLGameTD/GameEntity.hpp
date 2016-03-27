//
//  GameEntity.hpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 3/24/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#ifndef GameEntity_hpp
#define GameEntity_hpp

#include <iostream>
#include <list>

class GameEntity
{
public:
    std::unique_ptr<GameEntity> parent;
    std::list<std::unique_ptr<GameEntity>> children;
};

#endif /* GameEntity_hpp */
