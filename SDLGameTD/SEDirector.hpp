//
//  Director.hpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 3/29/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#ifndef Director_hpp
#define Director_hpp

#include "SETransform.hpp"
#include "SESprite.hpp"
#include "StartScene.hpp"

NS_SE_BEGIN

class SEDirector
{
private:
    static SEDirector* _instance;
    SEGameEntity* _currentScene;
    
public:
    SEDirector ();
    
    static SEDirector* getInstance ();
    SEGameEntity* getCurrentScene ();
    
    void InitStartScene ();
    
    static void LevelOrderTraversal (SEGameEntity* root);
};

NS_SE_END

#endif /* Director_hpp */
