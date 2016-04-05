//
//  StartScene.cpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 3/30/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#include "TagManager.hpp"
#include "Heroine.hpp"
#include "Monster.hpp"
#include "StartScene.hpp"

bool StartScene::init()
{
    if (SEGameEntity::init())
    {
        SEGameEntity* camp1 = SEGameEntity::create();
        this->addChild(camp1, TagManager::CAMP_1);
        
        Monster* monster = Monster::create("./images/undead01.png", 200, 200);
        camp1->addChild(monster);
        
        SEGameEntity* camp2 = SEGameEntity::create();
        this->addChild(camp2, TagManager::CAMP_2);
        
        Heroine* hero = Heroine::create("./images/heroine01.png", 100, 100);
        camp2->addChild(hero, TagManager::PLAYER);
        
        return true;
    }
    
    return false;
}

StartScene* StartScene::create()
{
    StartScene *ge = new StartScene ();
    if (ge && ge->init())
    {
        ge->autoRelease();
        return ge;
    }
    else
    {
        //        CC_SAFE_DELETE(ge);
        return nullptr;
    }
}