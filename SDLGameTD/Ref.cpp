//
//  Ref.cpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 3/29/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#include "AutoReleasePool.hpp" // 这句inclue不能放在GameEntity.h里，但是可以放在.cpp里，费解
#include "Ref.hpp"

int Ref::getRefCount()
{
    return _referenceCount;
}

void Ref::autorelease()
{
    PoolManager::getInstance()->getCurPool()->addEntity(this);
}

void Ref::release ()
{
    _referenceCount--;
}

void Ref::retain ()
{
    _referenceCount++;
}
