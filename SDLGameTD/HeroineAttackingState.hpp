//
//  HeroineAttackingState.hpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 4/4/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#ifndef HeroineAttackingState_hpp
#define HeroineAttackingState_hpp

#include "HeroineState.hpp"

class HeroineAttackingState : public HeroineState
{
public:
    HeroineAttackingState () {}
//    virtual HeroineState* handleInput (Heroine& heroine, SDL_Event e);
    virtual void update (Heroine& heroine);
};

#endif /* HeroineAttackingState_hpp */
