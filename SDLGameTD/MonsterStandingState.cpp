//
//  MonsterStandingState.cpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 4/3/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#include "TagManager.hpp"
#include "Monster.hpp"
#include "MonsterMovingState.hpp"
#include "MonsterAttackingState.hpp"
#include "MonsterStandingState.hpp"

void MonsterStandingState::update (Monster& monster)
{
    // waiting for the target
    SEGameEntity* camp2 = SEDirector::getInstance()->getCurrentScene()->getChildByTag(TagManager::CAMP_2);
    for (int i = 0; i < camp2->children.size(); i++)
    {
        if (monster.isInDis(camp2->children[i], monster.getAttackDis()))
        {
            monster.setTarget(camp2->children[i]);
            monster.changeState(new MonsterAttackingState());
            break;
        }
        if (monster.isInDis(camp2->children[i], monster.getPatrolDis()))
        {
            monster.setTarget(camp2->children[i]);
            monster.changeState(new MonsterMovingState());
            break;
        }
    }
}
