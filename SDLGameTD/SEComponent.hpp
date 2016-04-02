//
//  Component.hpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 3/28/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#ifndef Component_hpp
#define Component_hpp

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>

#include "SERef.hpp"

NS_SE_BEGIN

class SEComponent : public SERef
{
public:
    std::string title;
};

NS_SE_END

#endif /* Component_hpp */
