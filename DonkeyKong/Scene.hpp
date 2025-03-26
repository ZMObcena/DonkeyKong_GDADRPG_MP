#pragma once

#include "Enum/SceneTag.hpp"
#include "GameObject.hpp"

class Scene {
    protected:
        SceneTag ETag;

    public:
        Scene(SceneTag ETag);

    public:
        virtual void onLoadResources() = 0;
        virtual void onLoadObjects() = 0;
        virtual void onUnloadResources() = 0;
        virtual void onUnloadObjects();
        
    protected:
        void registerObject(GameObject* pGameObject);
        
    public:
        SceneTag getTag();
};
