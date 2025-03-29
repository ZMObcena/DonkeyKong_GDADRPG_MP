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
#include "BarrelHandler.h"
#include "GameScreen.h"
#include "Hammer.h"


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

	FloorHandler* floorHandler = new FloorHandler(20, "FloorHandler", holder);
	holder->attachComponent(floorHandler);
	this->registerObject(holder);

	holder = new EmptyGameObject("Barrel Holder");
	BarrelHandler* barrelHandler = new BarrelHandler(30, "BarrelHandler", holder);
	holder->attachComponent(barrelHandler);
	this->registerObject(holder);

	holder = new EmptyGameObject("HammerPool Holder");
	this->registerObject(holder);
	GameObjectPool* hammerPool = new GameObjectPool(ObjectPoolHolder::HAMMER_POOL_TAG, 10, new Hammer("Hammer"), holder);
	hammerPool->initialize();
	ObjectPoolHolder::getInstance()->registerObjectPool(hammerPool);

	GameScreen* ui = new GameScreen("GameScreen");
	this->registerObject(ui);
	
	Player* player = new Player("Player");
	this->registerObject(player);
	player->getTransformable()->setPosition(630, 950);	
	
	DonkeyKong* dk = new DonkeyKong("DonkeyKong");
	this->registerObject(dk);
	dk->getTransformable()->setPosition(630, 215);


	// Spawn Floors
	GameObjectPool* floorPool = ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::FLOOR_POOL_TAG);

	for (int i = 0; i < 5; ++i)
	{
		float y = 1000 - (i * 180); // Start at 1000 and decrease by 180 for each set
		for (int j = 0; j < 1; ++j)
		{
			// Alternates between (1920/2 + 150) and (1920/2 - 150)
			float x = (i % 2 == 0) ? (1920 / 2 - 40) : (1920 / 2 + 40);

			FloorManager::getInstance()->setDestination(x, y);
			floorPool->requestPoolable();
		}
	}

	// Spawn hammers
	hammerPool = ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::HAMMER_POOL_TAG);
	FloorManager::getInstance()->setDestination(830, 950);
	hammerPool->requestPoolable();

}

void Level1Scene::onUnloadResources()
{

}

sf::Vector2f Level1Scene::getDestination()
{
	return this->dest;
}