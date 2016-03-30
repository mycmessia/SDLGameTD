//
//  AutoReleasePool.hpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 3/29/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#ifndef AutoReleasePool_hpp
#define AutoReleasePool_hpp

#include "Ref.hpp"

class AutoReleasePool
{
private:
    std::vector<Ref*> _vectorPool;
    
public:
    void addEntity (Ref*);
    
    void autoDelete ();
};

class PoolManager
{
private:
    static PoolManager* _instance;
    
    AutoReleasePool* _currentPool;
    
public:
    static PoolManager* getInstance();
    
    void setCurPool ();
    AutoReleasePool* getCurPool ();
};

#endif /* AutoReleasePool_hpp */
