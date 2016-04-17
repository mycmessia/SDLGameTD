//
//  UIButton.cpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 4/16/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#include "UIButton.hpp"

SDL_Rect* UIButton::getClip()
{
    return &_buttonClip;
}

void UIButton::handleInput(SDL_Event e)
{
    if (isClickIn(e) && onClick)
    {
        onClick (e);
    }
}

bool UIButton::init(SDL_Texture* sharedTexture, int x, int y)
{
    if (SEClipSprite::initWithSharedTexture(sharedTexture, x, y))
    {
        _width = 34;
        
        _height = 34;
        
        _buttonClip = {110, 941, _width, _height};
        
        setHandleInput(true);
        
        setSwallowEvent(true);
        
        return true;
    }
    
    return false;
}

UIButton* UIButton::createFromSharedTexture(SDL_Texture* sharedTexture, int x, int y)
{
    UIButton *ge = new UIButton();
    if (ge && ge->init(sharedTexture, x, y))
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