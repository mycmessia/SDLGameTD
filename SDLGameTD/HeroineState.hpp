//
//  HeroineState.hpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 3/27/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#ifndef HeroineState_hpp
#define HeroineState_hpp

#include "SimpleEngine.h"

class Heroine;
/**
 * There are four types of state: stand, move, attack, skill, underAttack
 */
class HeroineState
{
public:
    virtual void handleInput (Heroine& heroine, SDL_Event e) {}
    virtual void update (Heroine& heroine) {}
};

#endif /* HeroineState_hpp */
