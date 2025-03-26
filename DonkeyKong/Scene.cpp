#include "Scene.hpp"

Scene::Scene(SceneTag ETag) {
    this->ETag = ETag;
}

void Scene::onUnloadObjects() {
    GameObjectManager::getInstance()->deleteAllObjects();
}

void Scene::registerObject(GameObject* pGameObject) {
    GameObjectManager::getInstance()->addObject(pGameObject);
}

SceneTag Scene::getTag() {
    return this->ETag;
}
