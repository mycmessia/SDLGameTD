//
//  MoveEntity.hpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 4/8/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#ifndef MoveEntity_hpp
#define MoveEntity_hpp

#include "SimpleEngine.h"

USING_NS_SE;

enum MoveDir {Left, Right, Up, Down};

class MoveEntity : public SEClipSprite
{
protected:
    MoveDir _moveDir;
    
public:
    SDL_Rect leftClips[4];
    SDL_Rect rightClips[4];
    SDL_Rect upClips[4];
    SDL_Rect downClips[4];
    int frame;
    
    virtual SDL_Rect* getClip ();
    
    MoveDir getMoveDir ();
    void setMoveDir (MoveDir md);
    
    virtual bool init (std::string texture, int x, int y);
};

#endif /* MoveEntity_hpp */
