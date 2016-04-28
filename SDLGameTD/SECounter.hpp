//
//  Counter.hpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 4/28/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#ifndef Counter_hpp
#define Counter_hpp

#include "SEGameEntity.hpp"

NS_SE_BEGIN

class SECounter : public SEGameEntity
{
private:
    int _currentCount;
    int _maxCount;
    
public:
    void setMaxCount (int max);
    void count (int step);
    bool isReachMax ();
    void reset ();
    
    static SECounter* create (int maxCount);
    virtual bool init (int maxCount);
};

NS_SE_END

#endif /* Counter_hpp */
