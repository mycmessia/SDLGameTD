//
//  StartScene.cpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 3/30/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#include "Heroine.hpp"
#include "StartScene.hpp"

bool StartScene::init()
{
    if (SEGameEntity::init())
    {
        Heroine* hero = Heroine::create("./images/heroine01.png", 100, 100);
        this->addChild(hero);
        
        return true;
    }
    
    return false;
}

StartScene* StartScene::create()
{
    StartScene *ge = new StartScene ();
    if (ge && ge->init())
    {
        ge->autorelease();
        return ge;
    }
    else
    {
        //        CC_SAFE_DELETE(ge);
        return nullptr;
    }
}