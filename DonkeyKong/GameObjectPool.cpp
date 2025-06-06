#include "GameObjectPool.h"
#include "GameObjectManager.h"
#include <iostream>

GameObjectPool::GameObjectPool(std::string tag, int nPoolSize, APoolable* pPoolableReference, AGameObject* pParent) {
    this->tag = tag;
    this->maxPoolSize = nPoolSize;
    this->objectCopy = pPoolableReference;
    this->parent = pParent;
}

GameObjectPool::~GameObjectPool()
{
    delete this->objectCopy;
    this->objectCopy = nullptr;
    this->parent = nullptr;
}

void GameObjectPool::initialize() {
    for (int i = 0; i < this->maxPoolSize; i++) {
        APoolable* pPoolableObject = this->objectCopy->clone();

        if (this->parent != nullptr)
            this->parent->attachChild(pPoolableObject);
        else
            GameObjectManager::getInstance()->addObject(pPoolableObject);

        pPoolableObject->setEnabled(false);
        this->availableObjects.push_back(pPoolableObject);
    }
}

bool GameObjectPool::hasObjectAvailable(int requestSize)
{
    return requestSize <= this->availableObjects.size();
}

APoolable* GameObjectPool::requestPoolable() {
    if (this->hasObjectAvailable(1)) {
        APoolable* pPoolableObject = this->availableObjects[this->availableObjects.size() - 1];
        this->availableObjects.erase(this->availableObjects.begin() + this->availableObjects.size() - 1);
        this->usedObjects.push_back(pPoolableObject);
        this->setEnabled(pPoolableObject, true);
        return pPoolableObject;
    }
    else 
    {
        std::cout << "No more poolable " << this->objectCopy->getName() << " available." << std::endl;
    }

    return NULL;
}

std::vector<APoolable*> GameObjectPool::requestPoolableBatch(int size)
{
    std::vector<APoolable*> returnList;
    if (this->hasObjectAvailable(size))
    {
        for (int i = 0; i < size; i++)
        {
            returnList.push_back(this->requestPoolable());
        }
    }

    return returnList;
}


void GameObjectPool::releasePoolable(APoolable* pPoolableObject) {
    int nIndex = -1;

    for (int i = 0; i < this->usedObjects.size() && nIndex == -1; i++) {
        if (this->usedObjects[i] == pPoolableObject)
            nIndex = i;
    }

    if (nIndex != -1) {
        this->availableObjects.push_back(pPoolableObject);
        this->usedObjects.erase(this->usedObjects.begin() + nIndex);
        this->setEnabled(pPoolableObject, false);
    }
}

void GameObjectPool::setEnabled(APoolable* pPoolableObject, bool bEnabled) {
    if (bEnabled)
    {
        pPoolableObject->setEnabled(true);
        pPoolableObject->onActivate();
    }
    else
    {
        pPoolableObject->setEnabled(false);
        pPoolableObject->onRelease();
    }
}

std::string GameObjectPool::getTag() {
    return this->tag;
}
