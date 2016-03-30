//
//  Director.hpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 3/29/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#ifndef Director_hpp
#define Director_hpp

#include "Transform.hpp"
#include "Sprite.hpp"
#include "StartScene.hpp"

class Director
{
private:
    static Director* _instance;
    GameEntity* _currentScene;
    
public:
    Director ();
    
    static Director* getInstance ();
    GameEntity* getCurrentScene ();
    
    void InitStartScene ();
    
    static void DrawSprite (Sprite* ge);
    static void LevelOrderTraversal (GameEntity* root, SDL_Event e);
};

#endif /* Director_hpp */
