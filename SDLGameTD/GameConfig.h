//
//  GameConfig.h
//  SDLGameTD
//
//  Created by 梅宇宸 on 4/27/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#ifndef GameConfig_h
#define GameConfig_h

#include "SimpleEngine.h"

USING_NS_SE;

class GameConfig
{
public:
    static std::string DEFAULT_FONT;
};

std::string GameConfig::DEFAULT_FONT = "./resources/fonts/Miss Issippi Demo.ttf";

#endif /* GameConfig_h */
