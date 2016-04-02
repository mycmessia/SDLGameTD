//
//  Transform.hpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 3/28/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#ifndef Transform_hpp
#define Transform_hpp

#include "SEComponent.hpp"

NS_SE_BEGIN

class SETransform : public SEComponent
{
public:
    int x;
    int y;
    
    SETransform ();
    
    static SETransform* create (int x, int y);
    
    virtual bool init (int x, int y);
};

NS_SE_END

#endif /* Transform_hpp */
