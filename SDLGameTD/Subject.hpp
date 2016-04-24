//
//  Subject.hpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 4/24/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#ifndef Subject_hpp
#define Subject_hpp

#include "Observer.hpp"

USING_NS_SE;

class Subject
{
private:
    static Subject* _instance;
    std::vector<Observer*> _obsVector;
    
public:
    static Subject* getInstance ();
    virtual ~Subject ();
    
    void addObserver (Observer* observer);
    void removeObserver (Observer* observer);
    
    void notify (SEGameEntity& entity, GAME_EVENT event);
};

#endif /* Subject_hpp */
