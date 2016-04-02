//
//  EventListener.hpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 3/31/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#ifndef EventListener_hpp
#define EventListener_hpp

#include "SEGameEntity.hpp"

NS_SE_BEGIN

class SEEventListener : public SEGameEntity
{
private:
    static SEEventListener* _instance;
public:
    static SEEventListener* getInstance ();
    void dispatchEvent (SDL_Event event);
};

NS_SE_END

#endif /* EventListener_hpp */
