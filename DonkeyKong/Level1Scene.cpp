#include "Level1Scene.h"

#include <iostream>
#include "TextureManager.h"
#include "SceneManager.h"
#include "PhysicsManager.h"
#include "Player.h"
#include "Floor.h"

Level1Scene::Level1Scene() : AScene("Level1Scene") {}

void Level1Scene::onLoadResources()
{
	TextureManager::getInstance()->loadAll();
}

void Level1Scene::onLoadObjects()
{
	EmptyGameObject* holder = new EmptyGameObject("PhysicsManager Holder");
	PhysicsManager::initialize("PhysicsManager", holder);
	this->registerObject(holder);

	Player* player = new Player("Player");
	this->registerObject(player);
	player->getTransformable()->setPosition(1920 / 2, 800);

	Floor* floor = new Floor("Floor");
	this->registerObject(floor);
	floor->getTransformable()->setPosition(1920 / 2, 400);
	floor->getTransformable()->setScale(.5f, .5f);
}

void Level1Scene::onUnloadResources()
{

}