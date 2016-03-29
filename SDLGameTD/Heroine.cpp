//
//  Heroine.cpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 3/27/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#include "Heroine.hpp"

Heroine::Heroine ()
{
    
}


bool Heroine::init (std::string texture, int x, int y)
{
    bool bo = Sprite::init(texture, x, y);
    
    if (bo)
    {
        _handleInput = true;
    
        _state = new StandingState ();
    
        return true;
    }
    
    return false;
}

Heroine* Heroine::create (std::string texture, int x, int y)
{
    Heroine *ge = new Heroine ();
    if (ge && ge->init(texture, x, y))
    {
        //        ge->autorelease();
        return ge;
    }
    else
    {
        //        CC_SAFE_DELETE(ge);
        return nullptr;
    }
}