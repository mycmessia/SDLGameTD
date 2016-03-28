//
//  InputHandler.hpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 3/23/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#ifndef InputHandler_hpp
#define InputHandler_hpp

#include <SDL2/SDL.h>
#include "Command.hpp"

class InputHandler
{
public:
    InputHandler ();
    ~InputHandler ();
    void handleInput (SDL_Event e);
    void bindCommand ();
private:
    Command* buttonA_;
    Command* buttonB_;
};

#endif /* InputHandler_hpp */
