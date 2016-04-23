//
//  MonsterGenerator.cpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 4/23/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#include "TagManager.hpp"
#include "MonsterGenerator.hpp"
#include "Monster.hpp"

void MonsterGenerator::createMonster()
{
    SEGameEntity* camp = SEDirector::getInstance()->getCurrentScene()->getChildByTag(TagManager::CAMP_1);
    
    Monster* monster = Monster::create("./resources/role/11000031.png", -100, 200);
    
    camp->addChild(monster);
}

void MonsterGenerator::update()
{
    
}

bool MonsterGenerator::init()
{
    if (SEGameEntity::init())
    {
        counter = 0;
        
        createMonster();
        
        return true;
    }
    
    return false;
}

MonsterGenerator* MonsterGenerator::create()
{
    MonsterGenerator *ge = new MonsterGenerator ();
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