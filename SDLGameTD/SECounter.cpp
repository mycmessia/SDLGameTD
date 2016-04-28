//
//  Counter.cpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 4/28/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#include "SECounter.hpp"

USING_NS_SE;

void SECounter::setMaxCount(int max)
{
    _maxCount = max;
}

void SECounter::count(int step)
{
    _currentCount += step;
}

bool SECounter::isReachMax()
{
    if (_currentCount >= _maxCount)
        return true;
    
    return false;
}

void SECounter::reset()
{
    _currentCount = 0;
}

bool SECounter::init(int maxCount)
{
    if (SEGameEntity::init())
    {
        setMaxCount(maxCount);
        
        reset();
        
        return true;
    }
    
    return false;
}

SECounter* SECounter::create(int maxCount)
{
    SECounter *ge = new SECounter ();
    if (ge && ge->init(maxCount))
    {
        ge->autoRelease();
        return ge;
    }
    else
    {
        SE_SAFE_DELETE(ge);
        return nullptr;
    }
}