//
//  Transform.hpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 3/28/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#ifndef Transform_hpp
#define Transform_hpp

#include "Component.hpp"

class Transform : public Component
{
public:
    float x;
    float y;
    
    Transform (float x, float y);
};

#endif /* Transform_hpp */
