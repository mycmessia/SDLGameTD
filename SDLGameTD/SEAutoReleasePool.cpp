//
//  AutoReleasePool.cpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 3/29/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#include "SEAutoReleasePool.hpp"

USING_NS_SE;

void SEAutoReleasePool::addEntity(SERef * ge)
{
    ge->retain();
    _vectorPool.push_back(ge);
}

void SEAutoReleasePool::autoDelete()
{
    for (int i = (int)_vectorPool.size() - 1; i >= 0; i--)
    {
        if (_vectorPool[i]->getRefCount() == 0)
        {
            delete _vectorPool[i];
            _vectorPool.erase(_vectorPool.begin()+i);
        }
    }
}

/**
 * PoolManager
 */
SEPoolManager* SEPoolManager::_instance = nullptr;

void SEPoolManager::setCurPool()
{
    _currentPool = new SEAutoReleasePool;
}

SEAutoReleasePool* SEPoolManager::getCurPool()
{
    return _currentPool;
}

SEPoolManager* SEPoolManager::getInstance()
{
    if (_instance == nullptr)
    {
        _instance = new SEPoolManager;
        
        _instance->setCurPool();
    }
    
    return _instance;
}