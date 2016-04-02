//
//  Ref.cpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 3/29/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#include "SEAutoReleasePool.hpp" // 这句inclue不能放在Ref.hpp里，但是可以放在.cpp里，费解
#include "SERef.hpp"

USING_NS_SE;

int SERef::getRefCount()
{
    return _referenceCount;
}

void SERef::autorelease()
{
    SEPoolManager::getInstance()->getCurPool()->addEntity(this);
}

void SERef::release ()
{
    _referenceCount--;
}

void SERef::retain ()
{
    _referenceCount++;
}
