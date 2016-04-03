//
//  GameEntity.hpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 3/24/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#ifndef GameEntity_hpp
#define GameEntity_hpp

#include "SEWindow.hpp"
#include "SEComponent.hpp"
#include "SETransform.hpp"

NS_SE_BEGIN

class SEGameEntity : public SERef
{
protected:
    bool _visible;
    bool _handleInput;
    unsigned int _referenceCount;
    bool _focus;
    int _tag;
    
public:
    SEGameEntity ();
    
    SEGameEntity* parent;
    std::vector<SEGameEntity*> children;
    
    SEGameEntity* getChildByTag (int tag);
    void addChild (SEGameEntity* child, int tag = 0);
    void removeChild (SEGameEntity* child);
    
    int getTag ();
    void setTag (int tag);
    
    bool getFocus ();
    void setFocus (bool bo);
    
    /**
     * components
     */
    std::vector<SEComponent*> components;
    
    SEComponent* getComponent (std::string name);
    void addComponent (SEComponent* compo);
    void removeComponent (std::string name);
    
    SDL_Point getPosition ();
    void setPosition (int x, int y);
    
    bool isVisible ();
    
    bool isHandleInput ();
    void setHandleInput (bool bo);
    virtual void handleInput (SDL_Event e) {};
    
    virtual void update () {};
    
    static SEGameEntity* create ();
    
    virtual bool init ();
    
    void autoRelease ();
};

NS_SE_END

#endif /* GameEntity_hpp */
