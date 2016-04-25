//
//  GameController.cpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 4/24/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#include "GameController.hpp"

USING_NS_SE;

void GameController::checkLose()
{
    _life -= 1;
    if (_life <= 0)
    {
        std::cout << "you win" << std::endl;
    }
    else
    {
        _lifeLabel->setString(std::to_string(_life));
    }
}

void GameController::onNotify (const SEGameEntity& entity, GAME_EVENT event)
{
    switch (event)
    {
        case MONSTER_PASS:
            checkLose();
            break;
            
        default:
            break;
    }
}

void GameController::createLifeUI()
{
    SEGameEntity* curScene = SEDirector::getInstance()->getCurrentScene();
    
    SESprite* life = SESprite::create("./resources/UI/life.png", 220, 10, 32, 32);
    curScene->addChild(life);
    
    _life = 10;
    
    _lifeLabel = SELabel::create(std::to_string(_life), "./resources/fonts/Miss Issippi Demo.ttf", {255, 255, 255, 0}, 32, 38, 4);
    life->addChild(_lifeLabel, TagManager::LIFE_COUNT);
}