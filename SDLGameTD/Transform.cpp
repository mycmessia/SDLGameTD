//
//  Transform.cpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 3/28/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#include "Transform.hpp"

Transform::Transform () {}

bool Transform::init(float x, float y)
{
    _referenceCount = 0;
    
    this->x = x;
    this->y = y;
    title = "Transform";
    
    return true;
}

Transform* Transform::create(float x, float y)
{
    Transform* ge = new Transform ();
    if (ge && ge->init(x, y))
    {
        ge->autorelease();
        return ge;
    }
    else
    {
        //        CC_SAFE_DELETE(ge);
        return nullptr;
    }
}