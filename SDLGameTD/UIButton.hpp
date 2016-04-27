//
//  UIButton.hpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 4/16/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#ifndef UIButton_hpp
#define UIButton_hpp

#include "SimpleEngine.h"

class UIBuildController;

typedef void (* clickCallback) (SDL_Event e);

class UIButton : public SEClipSprite
{
private:
    SDL_Texture* _sharedTexture;
    
    SDL_Rect _buttonClip;
    
public:
    clickCallback onClick = nullptr;
    
    virtual SDL_Rect* getClip ();
    
    virtual void handleInput (SDL_Event e);
    
    static UIButton* createFromSharedTexture (SDL_Texture* sharedTexture, SEPos pos);
    
    virtual bool init (SDL_Texture* sharedTexture, SEPos pos);
};

#endif /* UIButton_hpp */
