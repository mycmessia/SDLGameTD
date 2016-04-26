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

struct SEPos {float x; float y;};

class SETransform : public SEComponent
{
public:
    float x;
    float y;
    
    SETransform (float x, float y);
};

NS_SE_END

#endif /* Transform_hpp */
