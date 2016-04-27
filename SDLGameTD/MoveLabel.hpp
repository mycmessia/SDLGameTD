//
//  MoveLabel.hpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 4/27/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#ifndef MoveLabel_hpp
#define MoveLabel_hpp

#include "SimpleEngine.h"

USING_NS_SE;

class MoveLabel : public SELabel
{
private:
    int _moveSpeed;
    int _duringFrame;
public:
    virtual void update ();
    
    static MoveLabel* create (const std::string &message, const std::string &fontFile,
                            SDL_Color color, int fontSize, SEPos pos);
    
    virtual bool init (const std::string &message, const std::string &fontFile,
                       SDL_Color color, int fontSize, SEPos pos);
};

#endif /* MoveLabel_hpp */
