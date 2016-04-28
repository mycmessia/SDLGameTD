//
//  MonsterGenerator.hpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 4/23/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#ifndef MonsterGenerator_hpp
#define MonsterGenerator_hpp

#include "SimpleEngine.h"

USING_NS_SE;

class MonsterGenerator : public SEGameEntity
{
private:
    const int TIME_COUNTER = 0;
    const int WAVE_COUNTER = 1;
    const int BETWEEN_MONSTER_COUNTER = 2;
    const int BETWEEN_WAVE_COUNTER = 3;
    
    SECounter* _monsterCounter;
    SECounter* _waveCounter;
    SECounter* _betweenMonsterCounter;
    SECounter* _betweenWaveCounter;
    
public:
    void createMonster ();
    
    void update ();
    
    static MonsterGenerator* create ();
    
    virtual bool init ();
};

#endif /* MonsterGenerator_hpp */
