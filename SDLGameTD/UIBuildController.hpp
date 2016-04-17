//
//  UIBuildController.hpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 4/16/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#ifndef UIBuildController_hpp
#define UIBuildController_hpp

#include "SimpleEngine.h"

USING_NS_SE;

class UIBuildController : public SEGameEntity
{
private:
    SDL_Texture* _sharedTexture;
    
public:
    static std::string buildName;
    
    static void buildHero (SDL_Event e);
    
    SDL_Texture* getSharedTexture ();
    
    void setBuildName (std::string name);
    
    virtual void handleInput (SDL_Event e);
    
    static UIBuildController* create (std::string texture);
    
    virtual bool init (std::string texture);
};

#endif /* UIBuildController_hpp */
