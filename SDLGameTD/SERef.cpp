//
//  Ref.cpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 3/29/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#include "SERef.hpp"

USING_NS_SE;

int SERef::getRefCount()
{
    return _referenceCount;
}

void SERef::release ()
{
    _referenceCount--;
}

void SERef::retain ()
{
    _referenceCount++;
}
