#include "AScene.h"

AScene::AScene(std::string sceneName) 
{
    this->sceneName = sceneName;
}

void AScene::onUnloadObjects() {
    GameObjectManager::getInstance()->deleteAllObjectsInScene();
}

void AScene::registerObject(AGameObject* pGameObject) {
    GameObjectManager::getInstance()->addObject(pGameObject);
}

std::string AScene::getSceneName() {
    return this->sceneName;
}
