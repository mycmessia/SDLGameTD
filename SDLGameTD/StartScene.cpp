//
//  StartScene.cpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 3/30/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#include "Heroine.hpp"
#include "Monster.hpp"
#include "StartScene.hpp"

bool StartScene::init()
{
    if (SEGameEntity::init())
    {
//        SEGameEntity* enemyCollector = SEGameEntity::create();
//        this->addChild(enemyCollector);
        
        SEGameEntity* playerCollector = SEGameEntity::create();
        this->addChild(playerCollector);
        
        std::cout << playerCollector->getRefCount() << std::endl;
        
        Heroine* hero = Heroine::create("./images/heroine01.png", 100, 100);
        playerCollector->addChild(hero, 1);
        
        std::cout << hero->getRefCount() << std::endl;
        
//        Monster* monster = Monster::create("./images/undead01.png", 200, 200);
//        enemyCollector->addChild(monster);
        
        playerCollector->removeChild(hero);
        
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