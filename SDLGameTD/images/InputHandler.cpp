//
//  InputHandler.cpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 3/23/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//
#include "InputHandler.hpp"

InputHandler::InputHandler ()
{
    bindCommand();
}

InputHandler::~InputHandler()
{
    
}

void InputHandler::bindCommand()
{
    buttonA_.reset(new FireCommand ());
    buttonB_.reset(new JumpCommand ());
}

void InputHandler::handleInput(SDL_Event e)
{
    if (e.type == SDL_KEYDOWN)
    {
        switch (e.key.keysym.sym)
        {
            case SDLK_a:
                buttonA_->execute();
                break;
            case SDLK_b:
                buttonB_->execute();
                break;
        }
    }
}