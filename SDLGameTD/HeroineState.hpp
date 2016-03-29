//
//  HeroineState.hpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 3/27/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#ifndef HeroineState_hpp
#define HeroineState_hpp

#include "Sprite.hpp"

/**
 * There are four types of state: stand, walking, attack, skill, underAttack
 */
class HeroineState
{
public:
    virtual ~HeroineState () {}
    virtual void handleInput (GameEntity& heroine, SDL_Event e) {}
    virtual void update (GameEntity& heroine) {}
};

#endif /* HeroineState_hpp */
