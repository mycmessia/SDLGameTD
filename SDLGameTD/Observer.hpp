//
//  Observer.hpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 4/24/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#ifndef Observer_hpp
#define Observer_hpp

#include "SimpleEngine.h"

USING_NS_SE;

enum GAME_EVENT {
    MONSTER_DIE,
    HEROINE_DIE
};

class Observer
{
public:
    virtual ~Observer() {};
    virtual void onNotify (const SEGameEntity& entity, GAME_EVENT event) = 0;
};

#endif /* Observer_hpp */
