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
    
    /**
     * info
     * float speed; float hp; float attack; int attackSpeed; int attackDis; float armor; int patrolDis;
     */
    Monster* monster = Monster::create("./resources/role/11000031.png", {-100, 200}, {34, 34}, {120, 20, 16, 2, 48, 8, 96});
    
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