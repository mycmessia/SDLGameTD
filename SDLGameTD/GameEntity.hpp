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

class GameEntity : public Ref
{
protected:
    bool _visible;
    bool _handleInput;
    unsigned int _referenceCount;
    
public:
    GameEntity ();
    
    GameEntity* parent;
    std::vector<GameEntity*> children;
    
    void addChild (GameEntity* child);
    
    /**
     * components
     */
    std::vector<Component*> components;
    
    Component* getComponent (std::string name);
    void addComponent (Component* compo);
    void removeComponent (std::string name);
    
    bool isVisible ();
    
    bool isHandleInput ();
    
    virtual void handleInput (SDL_Event e) {};
    
    virtual void update () {};
    
    static GameEntity* create ();
    
    virtual bool init ();
};

#endif /* GameEntity_hpp */
