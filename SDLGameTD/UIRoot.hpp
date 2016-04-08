//
//  UIRoot.hpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 4/8/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#ifndef UIRoot_hpp
#define UIRoot_hpp

#include "SimpleEngine.h"

USING_NS_SE;

class UIRoot : public SEGameEntity
{
public:
    static UIRoot* create ();
    
    virtual bool init ();
};


#endif /* UIRoot_hpp */
