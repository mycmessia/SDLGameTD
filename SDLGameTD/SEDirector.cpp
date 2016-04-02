//
//  SEDirector.cpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 3/29/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#include "SEDirector.hpp"

USING_NS_SE;

// 类的静态成员变量必须先初始化再使用，虽然这个静态成员是私有的但是一样可以初始化
SEDirector* SEDirector::_instance = nullptr;

SEDirector::SEDirector () {}

SEDirector* SEDirector::getInstance ()
{
    if (_instance == nullptr)
    {
        _instance = new SEDirector ();
        
        _instance->InitStartScene();
    }
    
    return _instance;
}

void SEDirector::InitStartScene()
{
    _currentScene = StartScene::create();
}

SEGameEntity* SEDirector::getCurrentScene ()
{
    return _currentScene;
}

void SEDirector::DrawSprite (SESprite* ge)
{
    SDL_Rect dest = ge->getRect();
    
    SEWindow::Draw(ge->getTexture(), dest, ge->getClip());
}

void SEDirector::LevelOrderTraversal (SEGameEntity* root)
{
    std::queue<SEGameEntity*> queue;
    
    if (root != nullptr)
    {
        queue.push(root);
        
        while(!queue.empty())
        {
            SEGameEntity* ge = queue.front();
            
            ge->update();
            
            if (ge->isVisible())
            {
                SEDirector::DrawSprite((SESprite*)ge);
            }
            
            for (int i = 0; i < ge->children.size(); i++)
            {
                queue.push(ge->children[i]);
            }
            
            queue.pop();
        }
    }
}