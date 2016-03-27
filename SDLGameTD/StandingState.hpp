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
    virtual void handleInput (Heroine& heroine, SDL_Event e)
    {
        if (e.type == SDL_KEYDOWN)
        {
            switch (e.key.keysym.sym)
            {
                case SDLK_s:
                    std::cout << "handleInput standingState" << std::endl;
                    break;
            }
        }
    }
    
    virtual void update (Heroine& heroine)
    {
        std::cout << "update standingState" << std::endl;
    }
};

#endif /* StandingState_hpp */
