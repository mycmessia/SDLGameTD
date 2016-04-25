//
//  GameController.hpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 4/24/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#ifndef GameController_hpp
#define GameController_hpp

#include "Observer.hpp"

USING_NS_SE;

class GameController : public Observer
{
private:
    int _life;
    SELabel* _lifeLabel;
    
public:
    virtual void onNotify (const SEGameEntity& entity, GAME_EVENT event);
    
    void checkLose ();
    
    void createLifeUI ();
};

#endif /* GameController_hpp */
