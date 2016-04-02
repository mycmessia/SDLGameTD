//
//  Ref.hpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 3/29/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#ifndef Ref_hpp
#define Ref_hpp

#include <vector>

#include "SimpleEngineMacros.h"

NS_SE_BEGIN

class SERef
{
protected:
    unsigned int _referenceCount;
    
public:
    int getRefCount ();
    
    void autorelease ();
    
    void release ();
    
    void retain ();
};

NS_SE_END

#endif /* Ref_hpp */
