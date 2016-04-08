//
//  Sprite.hpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 3/28/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#ifndef Sprite_hpp
#define Sprite_hpp

#include "SEGameEntity.hpp"

NS_SE_BEGIN

class SESprite : public SEGameEntity
{
private:
    SDL_Texture* _texture;
    
protected:
    int _width;
    int _height;
    bool _useClip;
    
public:
    SESprite () {};
    virtual ~SESprite () {};
    
    bool isUseClip ();
    
    int getWidth ();
    int getHeight ();
    
    SDL_Texture* getTexture ();
    
    const SDL_Rect getRect ();
    
    bool isClickIn (SDL_Event e);
    
    static SESprite* create (std::string texture, int x, int y);
    
    virtual bool init (std::string texture, int x, int y);
    
    virtual void handleInput (SDL_Event e) {};
    
    virtual void update () {};
};

NS_SE_END

#endif /* Sprite_hpp */
