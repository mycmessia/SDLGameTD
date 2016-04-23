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
    int counter;
    const int MAX_COUNTER = 120;    // every two seconds create a monster
    
public:
    void createMonster ();
    
    void update ();
    
    static MonsterGenerator* create ();
    
    virtual bool init ();
};

#endif /* MonsterGenerator_hpp */
