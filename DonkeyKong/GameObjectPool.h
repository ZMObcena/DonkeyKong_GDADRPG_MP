#pragma once

#include "APoolable.h"
#include <vector>

class GameObjectPool
{
    public:
        GameObjectPool(std::string tag, int nPoolSize, APoolable* copy, AGameObject* parent);
        ~GameObjectPool();

        void initialize();
        bool hasObjectAvailable(int requestSize);
        APoolable* requestPoolable();
        std::vector<APoolable*> requestPoolableBatch(int size);

        void releasePoolable(APoolable* poolableObject);
        void releasePoolableBatch(std::vector<APoolable*> objectList);

        std::string getTag();

    private:
        std::string tag;
        APoolable* objectCopy = NULL;
        AGameObject* parent = NULL;
        int maxPoolSize = 200;
        std::vector<APoolable*> availableObjects;
        std::vector<APoolable*> usedObjects;

        void setEnabled(APoolable* pPoolableObject, bool bEnabled);
};

