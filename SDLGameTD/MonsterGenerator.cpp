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
    if (_waveCounter->isReachMax())
    {
        // you win
        return;
    }
    
    if (_betweenWaveCounter->isReachMax())
    {
        if (_betweenMonsterCounter->isReachMax())
        {
            createMonster();
            _monsterCounter->count(1);
            _betweenMonsterCounter->reset();
            
            if (_monsterCounter->isReachMax())
            {
                _waveCounter->count(1);
                _betweenWaveCounter->reset();
                _monsterCounter->reset();
            }
        }
        else
        {
            _betweenMonsterCounter->count(1);
        }
    }
    else
    {
        _betweenWaveCounter->count(1);
    }
}

bool MonsterGenerator::init()
{
    if (SEGameEntity::init())
    {
        _monsterCounter = SECounter::create(5);
        this->addChild(_monsterCounter, TIME_COUNTER);
        
        _waveCounter = SECounter::create(10);
        this->addChild(_waveCounter, WAVE_COUNTER);
        
        _betweenMonsterCounter = SECounter::create(60);
        this->addChild(_betweenMonsterCounter, BETWEEN_MONSTER_COUNTER);
        
        _betweenWaveCounter = SECounter::create(180);
        this->addChild(_betweenWaveCounter, BETWEEN_WAVE_COUNTER);
        
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