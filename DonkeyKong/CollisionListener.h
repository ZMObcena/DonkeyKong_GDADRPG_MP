#pragma once

#include "AGameObject.h"

class CollisionListener 
{
public:
    virtual void onCollisionEnter(AGameObject* pGameObject) = 0;
    virtual void onCollisionExit(AGameObject* pGameObject) = 0;

protected:
    CollisionListener() {}
};
