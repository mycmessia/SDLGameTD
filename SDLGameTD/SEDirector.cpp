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
SEDirector::~SEDirector() {SE_SAFE_DELETE(_instance);}

SEDirector* SEDirector::getInstance ()
{
    if (_instance == nullptr)
    {
        _instance = new SEDirector ();
        
        _instance->initStartScene();
    }
    
    return _instance;
}

void SEDirector::initStartScene()
{
    // 这个改动很重要，因为我在StartScene的初始化过程中获取_currentScene指针所以我必须确保
    // 在获取的时候这个指针有意义
    _currentScene = new StartScene ();
    _currentScene->init ();
}

SEGameEntity* SEDirector::getCurrentScene ()
{
    return _currentScene;
}

void SEDirector::levelOrderTraversal (SEGameEntity* root)
{
    std::queue<SEGameEntity*> queue;
    
    if (root != nullptr)
    {
        queue.push(root);
        
        while(!queue.empty())
        {
            SEGameEntity* ge = queue.front();
            
            ge->update();
            
            ge->draw();
            
            for (int i = 0; i < ge->children.size(); i++)
            {
                queue.push(ge->children[i]);
            }
            
            queue.pop();
        }
    }
}