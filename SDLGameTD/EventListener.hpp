//
//  EventListener.hpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 3/31/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#ifndef EventListener_hpp
#define EventListener_hpp

#include "GameEntity.hpp"

class EventListener : public GameEntity
{
private:
    static EventListener* _instance;
public:
    static EventListener* getInstance ();
    void dispatchEvent (SDL_Event event);
};

#endif /* EventListener_hpp */
