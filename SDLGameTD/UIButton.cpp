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

bool UIButton::init(SDL_Texture* sharedTexture, SEPos pos)
{
    if (SEClipSprite::initWithSharedTexture(sharedTexture, pos.x, pos.y))
    {
        _isUI = true;
        
        _width = 34;
        
        _height = 34;
        
        _buttonClip = {110, 905, _width, _height};
        
        setHandleInput(true);
        
        setSwallowEvent(true);
        
        return true;
    }
    
    return false;
}

UIButton* UIButton::createFromSharedTexture(SDL_Texture* sharedTexture, SEPos pos)
{
    UIButton *ge = new UIButton();
    if (ge && ge->init(sharedTexture, pos))
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