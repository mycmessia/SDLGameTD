//
//  UIRoot.cpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 4/8/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#include "UIRoot.hpp"

bool UIRoot::init()
{
    if (SEGameEntity::init())
    {
        return true;
    }
    
    return false;
}

UIRoot* UIRoot::create()
{
    UIRoot *ge = new UIRoot();
    if (ge && ge->init())
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