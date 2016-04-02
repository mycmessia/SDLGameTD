//
//  StartScene.hpp
//
//  游戏入口
//
//  SDLGameTD
//
//  Created by 梅宇宸 on 3/30/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#ifndef StartScene_hpp
#define StartScene_hpp

USING_NS_SE;

class StartScene : public SEGameEntity
{
public:
    static StartScene* create ();
    
    virtual bool init ();
};

#endif /* StartScene_hpp */
