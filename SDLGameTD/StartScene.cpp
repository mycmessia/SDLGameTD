//
//  StartScene.cpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 3/30/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#include "UIRoot.hpp"
#include "Heroine.hpp"
#include "Monster.hpp"
#include "StartScene.hpp"

bool StartScene::init()
{
    if (SEGameEntity::init())
    {
        SESprite* bg = SESprite::create("./resources/battle_background/cave.png", 0, 0, 320, 568);
        this->addChild(bg);
        
        SESprite* board = SESprite::create("./resources/UI/board2.png", 5, 60, 310, 48);
        this->addChild(board);
        
        SESprite* life = SESprite::create("./resources/UI/life.png", 220, 10, 32, 32);
        this->addChild(life);
        
//        SESprite* skill = SESprite::create("./resources/UI/skill1.png", 2, 2, 40, 40);
//        this->addChild(skill);
        
        UIRoot* root = UIRoot::create();
        this->addChild(root, TagManager::UI_ROOT);
        
        SEGameEntity* camp1 = SEGameEntity::create();
        this->addChild(camp1, TagManager::CAMP_1);

//        Monster* monster = Monster::create("./images/undead01.png", 240, 0);
//        camp1->addChild(monster);

        SEGameEntity* camp2 = SEGameEntity::create();
        this->addChild(camp2, TagManager::CAMP_2);

//        Heroine* hero = Heroine::create("./images/heroine01.png", 230, 520);
//        camp2->addChild(hero, TagManager::PLAYER);
        
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
        SE_SAFE_DELETE(ge);
        return nullptr;
    }
}