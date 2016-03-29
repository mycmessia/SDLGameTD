//
//  Director.hpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 3/29/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#ifndef Director_hpp
#define Director_hpp

#include "GameEntity.hpp"

class Director
{
private:
    static Director* _instance;
    GameEntity* _currentScene;
    
public:
    Director ();
    static Director* getInstance ();
    GameEntity* getCurrentScene ();
};

#endif /* Director_hpp */
