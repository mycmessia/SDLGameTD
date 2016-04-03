//
//  AutoReleasePool.hpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 3/29/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#ifndef AutoReleasePool_hpp
#define AutoReleasePool_hpp

#include "SEGameEntity.hpp"

NS_SE_BEGIN

class SEAutoReleasePool
{
private:
    std::vector<SEGameEntity*> _vectorPool;
    
public:
    void addEntity (SEGameEntity*);
    
    void autoDelete ();
};

class SEPoolManager
{
private:
    static SEPoolManager* _instance;
    
    SEAutoReleasePool* _currentPool;
    
public:
    static SEPoolManager* getInstance();
    
    void setCurPool ();
    SEAutoReleasePool* getCurPool ();
};

NS_SE_END

#endif /* AutoReleasePool_hpp */
