//
//  AutoReleasePool.cpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 3/29/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#include "AutoReleasePool.hpp"

void AutoReleasePool::addEntity(Ref * ge)
{
    ge->retain();
    _vectorPool.push_back(ge);
}

void AutoReleasePool::autoDelete()
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
PoolManager* PoolManager::_instance = nullptr;

void PoolManager::setCurPool()
{
    _currentPool = new AutoReleasePool;
}

AutoReleasePool* PoolManager::getCurPool()
{
    return _currentPool;
}

PoolManager* PoolManager::getInstance()
{
    if (_instance == nullptr)
    {
        _instance = new PoolManager;
        
        _instance->setCurPool();
    }
    
    return _instance;
}