//
//  Director.cpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 3/29/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#include "Director.hpp"

// 类的静态成员变量必须先初始化再使用，虽然这个静态成员是私有的但是一样可以初始化
Director* Director::_instance = nullptr;

Director::Director () {}

Director* Director::getInstance ()
{
    if (_instance == nullptr)
    {
        _instance = new Director ();
        
        _instance->InitStartScene();
    }
    
    return _instance;
}

void Director::InitStartScene()
{
    _currentScene = StartScene::create();
}

GameEntity* Director::getCurrentScene ()
{
    return _currentScene;
}

void Director::DrawSprite (Sprite* ge)
{
    Transform* trans = (Transform *)ge->getComponent("Transform");
    
    int x = trans->x;
    int y = trans->y;
    
    int w, h;
    SDL_Texture* texture = ge->getTexture();
    SDL_QueryTexture(texture, nullptr, nullptr, &w, &h);
    
    SDL_Rect dest = {x, y, w, h};
    
    Window::Draw(texture, dest);
}

void Director::LevelOrderTraversal (GameEntity* root, SDL_Event e)
{
    std::queue<GameEntity*> queue;
    
    if (root != nullptr)
    {
        queue.push(root);
        
        while(!queue.empty())
        {
            GameEntity* ge = queue.front();
            
            if (ge->isVisible())
            {
                Director::DrawSprite((Sprite*)ge);
            }
            
            if (ge->isHandleInput())
            {
                ge->handleInput (e);
            }
            
            for (int i = 0; i < ge->children.size(); i++)
            {
                queue.push(ge->children[i]);
            }
            
            queue.pop();
        }
    }
}