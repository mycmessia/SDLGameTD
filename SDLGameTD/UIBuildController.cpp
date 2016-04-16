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

std::string buildName;

void buildHero1 (SDL_Event e)
{
    buildName = "hero1";
}

SDL_Texture* UIBuildController::getSharedTexture()
{
    return _sharedTexture;
}

void UIBuildController::handleInput(SDL_Event e)
{
    if (isClickIn (e) && buildName == "hero1")
    {
        SEGameEntity* camp2 = SEDirector::getInstance()->getCurrentScene()->getChildByTag(TagManager::CAMP_2);
        
        Heroine* hero = Heroine::create("./images/heroine01.png", e.button.x, e.button.y);
        camp2->addChild(hero, TagManager::PLAYER);
        
        buildName = "";
    }
}

bool UIBuildController::init(std::string texture)
{
    if (SEGameEntity::init())
    {
        _sharedTexture = SEWindow::LoadImage(texture);
        
        UIButton* button1 = UIButton::createFromSharedTexture(_sharedTexture, 100, 100);
        this->addChild(button1);
        
        button1->onClick = buildHero1;
        
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
