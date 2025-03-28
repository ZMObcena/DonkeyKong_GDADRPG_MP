#include "Level1Scene.h"

#include <iostream>
#include "TextureManager.h"
#include "SceneManager.h"
#include "PhysicsManager.h"
#include "GameObjectPool.h"
#include "ObjectPoolHolder.h"
#include "Player.h"
#include "DonkeyKong.h"
#include "Floor.h"
#include "FloorHandler.h"
#include "FloorManager.h"
#include "GameScreen.h"


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

	holder = new EmptyGameObject("FloorManager Holder");
	this->registerObject(holder);
	FloorHandler* floorHandler = new FloorHandler(150, "FloorHandler", holder);
	holder->attachComponent(floorHandler);
	this->registerObject(holder);

	GameObjectPool* floorPool = ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::FLOOR_POOL_TAG);

	GameScreen* ui = new GameScreen("GameScreen");
	this->registerObject(ui);
	
	Player* player = new Player("Player");
	this->registerObject(player);
	player->getTransformable()->setPosition(630, 950);	
	
	DonkeyKong* dk = new DonkeyKong("DonkeyKong");
	this->registerObject(dk);
	dk->getTransformable()->setPosition(630, 215);

	for (int i = 0; i < 5; ++i)
	{
		float y = 1000 - (i * 180); // Start at 900 and decrease by 200 for each set
		for (int j = 0; j < 1; ++j)
		{
			//float x = 150 + (j * 25); // Start at 150 and increase by 25 for each floor
			float x = 1920 / 2;
			FloorManager::getInstance()->setDestination(x, y);
			floorPool->requestPoolable();
		}
	}
}

void Level1Scene::onUnloadResources()
{

}

sf::Vector2f Level1Scene::getDestination()
{
	return this->dest;
}