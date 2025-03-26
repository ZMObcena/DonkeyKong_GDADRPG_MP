#pragma once

#include "AGameObject.h"
#include "GameObjectManager.h"

class AScene
{
public:
    AScene(std::string sceneName);

    virtual void onLoadResources() = 0;
    virtual void onLoadObjects() = 0;
    virtual void onUnloadResources() = 0;
    virtual void onUnloadObjects();

    std::string getSceneName();

protected:
    void registerObject(AGameObject* pGameObject);
    std::string sceneName;
};
