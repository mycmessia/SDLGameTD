//
//  Transform.cpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 3/28/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#include "SETransform.hpp"

USING_NS_SE;

SETransform::SETransform () {}

bool SETransform::init(int x, int y)
{
    _referenceCount = 0;
    
    this->x = x;
    this->y = y;
    title = "Transform";
    
    return true;
}

SETransform* SETransform::create(int x, int y)
{
    SETransform* ge = new SETransform ();
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