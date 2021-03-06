//
//  SEClipSprite.hpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 4/8/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#ifndef SEClipSprite_hpp
#define SEClipSprite_hpp

#include "SESprite.hpp"

NS_SE_BEGIN

class SEClipSprite : public SESprite
{
public:
    SDL_Rect defaultRect;
    
    virtual SDL_Rect* getClip ();
    
    virtual void draw ();
    
    static SEClipSprite* create (std::string texture, int x, int y);
    
    virtual bool init (std::string texture, int x, int y);
    
    virtual bool initWithSharedTexture (SDL_Texture* sharedTexture, int x, int y);
};

NS_SE_END

#endif /* SEClipSprite_hpp */
