//
//  MovingState.hpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 3/30/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#ifndef MovingState_hpp
#define MovingState_hpp

#include "HeroineState.hpp"

class HeroineMovingState : public HeroineState
{
private:
    SE_Point _dest;
    
public:
    HeroineMovingState (int x, int y);
    virtual void handleInput (Heroine& heroine, SDL_Event e);
    virtual void update (Heroine& heroine);
};

#endif /* MovingState_hpp */
