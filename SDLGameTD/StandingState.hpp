//
//  StandingState.hpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 3/27/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#ifndef StandingState_hpp
#define StandingState_hpp

#include "HeroineState.hpp"

class StandingState : public HeroineState
{
public:
    StandingState () {}
    virtual void handleInput (GameEntity& heroine, SDL_Event e);
    virtual void update (GameEntity& heroine);
};

#endif /* StandingState_hpp */
