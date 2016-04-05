//
//  MonsterMovingState.hpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 4/3/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#ifndef MonsterMovingState_hpp
#define MonsterMovingState_hpp

#include "MonsterState.hpp"

class MonsterMovingState : public MonsterState
{
private:
    SDL_Point _dest;
    
public:
    MonsterMovingState ();
    virtual void update (Monster& heroine);
};

#endif /* MonsterMovingState_hpp */
