//
//  UIBuildController.cpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 4/16/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#include "UIBuildController.hpp"

bool UIBuildController::init(std::string texture)
{
    if (SEGameEntity::init())
    {
        _sharedTexture = SEWindow::LoadImage(texture);
        
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
