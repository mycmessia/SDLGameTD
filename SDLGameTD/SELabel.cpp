//
//  SELabel.cpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 4/21/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#include "SELabel.hpp"

USING_NS_SE;

int SELabel::getWidth () {return _width;}
int SELabel::getHeight () {return _height;}

SDL_Texture* SELabel::getTexture ()
{
    return _texture;
}

const SDL_Rect SELabel::getRect ()
{
    SE_Point destPos = {getPosition().x, getPosition().y};
    
    SEGameEntity* posParent = this->parent;
    while (posParent)
    {
        destPos = {destPos.x + posParent->getPosition().x, destPos.y + posParent->getPosition().y};
        posParent = posParent->parent;
    }
    
    SDL_Rect worldRect = {
        (int)(destPos.x),
        (int)(destPos.y),
        _width,
        _height
    };
    
    return worldRect;
}

std::string SELabel::getString ()
{
    return _message;
}

void SELabel::setString (std::string str)
{
    _message = str;
    _width = (int)(_message.length() * _fontSize / 2);
    _texture = SEWindow::RenderText(_message, _fontFile, _fontColor, _fontSize);
}

void SELabel::draw()
{
    if (isVisible())
    {
        SEWindow::Draw(getTexture(), getRect());
    }
}

bool SELabel::init(const std::string &message, const std::string &fontFile, SDL_Color color, int fontSize, SEPos pos)
{
    if (SEGameEntity::init())
    {
        _visible = true;
        
        _fontFile = fontFile;
        _fontSize = fontSize;
        _fontColor = color;
        _message = message;
        
        _width = (int)(message.length() * fontSize / 2);
        _height = fontSize;
        
        setPosition(pos.x, pos.y);
        
        _texture = SEWindow::RenderText(_message, _fontFile, _fontColor, _fontSize);
        
        return true;
    }
    
    return false;
}

SELabel* SELabel::create(const std::string &message, const std::string &fontFile, SDL_Color color, int fontSize, SEPos pos)
{
    SELabel *ge = new SELabel ();
    if (ge && ge->init(message, fontFile, color, fontSize, pos))
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
