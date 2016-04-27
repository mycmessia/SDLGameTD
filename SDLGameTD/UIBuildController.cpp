//
//  UIBuildController.cpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 4/16/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#include "UIBuildController.hpp"
#include "UIButton.hpp"
#include "Heroine.hpp"

std::string UIBuildController::buildName = "";

void UIBuildController::buildHero (SDL_Event e)
{
    buildName = "hero2";
    
    SEGameEntity* camp2 = SEDirector::getInstance()->getCurrentScene()->getChildByTag(TagManager::CAMP_2);
    
    for (int i = 0; i < camp2->children.size(); i++)
    {
        camp2->children[i]->setFocus (false);
    }
}

SDL_Texture* UIBuildController::getSharedTexture()
{
    return _sharedTexture;
}

void UIBuildController::handleInput(SDL_Event e)
{
    if (isClickIn (e) && buildName != "")
    {
        SEGameEntity* camp2 = SEDirector::getInstance()->getCurrentScene()->getChildByTag(TagManager::CAMP_2);
        
        /**
         * info
         * float speed; float hp; float attack; int attackSpeed; int attackDis; float armor; int patrolDis;
         */
        std::string url = "./resources/role/" + buildName + ".png";
        
        Heroine* hero = Heroine::create(url,
                                        {(float)e.button.x, (float)e.button.y}, {34, 34},
                                        {90, 40, 10, 2, 48, 12, 96});
        camp2->addChild(hero, TagManager::PLAYER);
        
        buildName = "";
    }
}

bool UIBuildController::init(std::string texture)
{
    if (SEGameEntity::init())
    {
        _sharedTexture = SEWindow::LoadImage(texture);
        
        SESprite* board = (SESprite*)(SEDirector::getInstance()->getCurrentScene()->getChildByTag(TagManager::BUILD_BORAD));
        
        UIButton* button1 = UIButton::createFromSharedTexture(_sharedTexture, {20, 8});
        board->addChild(button1);
        
        button1->onClick = buildHero;
        
        setHandleInput(true);
        
        return true;
    }
    
    return false;
}

UIBuildController* UIBuildController::create(std::string texture)
{
    UIBuildController *ge = new UIBuildController();
    if (ge && ge->init(texture))
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
