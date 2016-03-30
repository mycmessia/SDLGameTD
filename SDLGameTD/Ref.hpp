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

class Ref
{
protected:
    unsigned int _referenceCount;
    
public:
    int getRefCount ();
    
    void autorelease ();
    
    void release ();
    
    void retain ();
};

#endif /* Ref_hpp */
