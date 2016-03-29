//
//  GameEntity.hpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 3/24/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#ifndef GameEntity_hpp
#define GameEntity_hpp

#include "Window.hpp"
#include "Component.hpp"

class GameEntity
{
protected:
    bool _visible;
    bool _handleInput;
    
public:
    GameEntity* parent;
    std::vector<GameEntity*> children;
    std::vector<Component*> components;
    
    GameEntity ();
    
    void addChild (GameEntity* child);
    Component* getComponent (std::string name);
    
    bool isVisible ();
    bool isHandleInput ();
    
    static GameEntity* create ();
    
    virtual bool init ();
    
    virtual void handleInput (SDL_Event e) {};
    
    virtual void update () {};
};

#endif /* GameEntity_hpp */
