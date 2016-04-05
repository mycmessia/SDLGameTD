//
//  GameEntity.cpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 3/24/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#include "SEAutoReleasePool.hpp" // 这句inclue不能放在Ref.hpp里，但是可以放在.cpp里，费解
#include "SEGameEntity.hpp"
#include "SEEventListener.hpp"

USING_NS_SE;

SEGameEntity::SEGameEntity ()
{
    _visible = false;
    _handleInput = false;
}

SEGameEntity::~SEGameEntity()
{
    std::cout << "SEGameEntity::~SEGameEntity()" << std::endl;
    
    // TODO remove all components and children
    removeAllComponents();
    
    removeAllChildren();
}

bool SEGameEntity::isVisible ()
{
    return _visible;
}

bool SEGameEntity::isHandleInput ()
{
    return _handleInput;
}

void SEGameEntity::setHandleInput(bool bo)
{
    _handleInput = bo;
    
    if (bo)
    {
        SEEventListener::getInstance()->addListener(this);
    }
    else
    {
        SEEventListener::getInstance()->removeListener(this);
    }
}

bool SEGameEntity::getFocus()
{
    return _focus;
}

void SEGameEntity::setFocus(bool bo)
{
    _focus = bo;
}

int SEGameEntity::getTag()
{
    return _tag;
}

void SEGameEntity::setTag(int tag)
{
    _tag = tag;
}

SEGameEntity* SEGameEntity::getChildByTag(int tag)
{
    for (int i = 0; i < children.size(); i++)
    {
        if (children[i]->getTag() == tag)
        {
            return children[i];
        }
    }
    
    std::cout << "Could not find a child tag = " << tag << std::endl;
    
    return nullptr;
}

void SEGameEntity::addChild(SEGameEntity *child, int tag)
{
    child->retain();
    
    child->parent = this;
    
    child->setTag(tag);
    
    children.push_back(child);
}

void SEGameEntity::removeChild(SEGameEntity *child)
{
    child->release();
    
    child->parent = nullptr;
    
    for (int i = 0; i < children.size(); i++)
    {
        if (children[i] == child)
        {
            children[i] = nullptr;  // Is this necessary?
            children.erase(children.begin() + i);
            break;
        }
    }
}

void SEGameEntity::removeAllChildren()
{
    for (int i = (int)(children.size() - 1); i >= 0; i--)
    {
        children[i]->release();
        children[i]->parent = nullptr;
        children[i] = nullptr;
        children.erase(children.begin() + i);
    }
}

void SEGameEntity::removeFromParent()
{
    this->parent->removeChild(this);
}

void SEGameEntity::addComponent(SEComponent *compo)
{
    components.push_back(compo);
}

SEComponent* SEGameEntity::getComponent(std::string name)
{
    for (int i = 0; i < components.size(); i++)
    {
        if (components[i]->title == name)
        {
            return components[i];
        }
    }
    
    std::cout << "Could not find component " << name << std::endl;
    return nullptr;
}

void SEGameEntity::removeComponent(std::string name)
{
    for (int i = 0; i < components.size(); i++)
    {
        if (components[i]->title == name)
        {
            SE_SAFE_DELETE(components[i]);
            components.erase(components.begin() + i);
            break;
        }
    }
}

void SEGameEntity::removeAllComponents()
{
    for (int i = (int)(components.size() - 1); i >= 0; i--)
    {
        SE_SAFE_DELETE(components[i]);
        components.erase(components.begin() + i);
    }
}

SDL_Point SEGameEntity::getPosition()
{
    SETransform* trans = (SETransform*)this->getComponent("Transform");
    
    return {trans->x, trans->y};
}

void SEGameEntity::setPosition (int x, int y)
{
    SETransform* trans = (SETransform*)this->getComponent("Transform");
    trans->x = x;
    trans->y = y;
}

bool SEGameEntity::init()
{
    _referenceCount = 0;
    
    addComponent(new SETransform(0, 0));
    
    return true;
}

void SEGameEntity::autoRelease()
{
    SEPoolManager::getInstance()->getCurPool()->addEntity(this);
}

SEGameEntity* SEGameEntity::create()
{
    SEGameEntity *ge = new SEGameEntity ();
    if (ge && ge->init())
    {
        ge->autoRelease();
        return ge;
    }
    else
    {
        SE_SAFE_DELETE(ge);
        return nullptr;
    }
}