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
#include "SpawnManager.h"
#include "BarrelHandler.h"
#include "LadderHandler.h"
#include "HammerHandler.h"
#include "GameScreen.h"
#include "Hammer.h"
#include "Border.h"
#include "Ladder.h"
#include "BGObject.h"
#include "LevelManager.h"

Level1Scene::Level1Scene() : AScene("Level1Scene") {}

void Level1Scene::onLoadResources()
{
	TextureManager::getInstance()->loadAll();
}

void Level1Scene::onLoadObjects()
{
	srand(time(nullptr));

	EmptyGameObject* holder = new EmptyGameObject("Physics Manager Holder");
	PhysicsManager::initialize("Physics Manager", holder);
	this->registerObject(holder);

	EmptyGameObject* barrelManager = new EmptyGameObject("Barrel Manager");
	BarrelHandler* barrelHandler = new BarrelHandler(100, "BarrelHandler", barrelManager);
	barrelManager->attachComponent(barrelHandler);
	this->registerObject(barrelManager);

	EmptyGameObject* ladderManager = new EmptyGameObject("Ladder Manager");
	LadderHandler* ladderHandler = new LadderHandler(20, "LadderHandler", ladderManager);
	ladderManager->attachComponent(ladderHandler);
	this->registerObject(ladderManager);

	EmptyGameObject* floorManager = new EmptyGameObject("Floor Manager");
	FloorHandler* floorHandler = new FloorHandler(30, "FloorHandler", floorManager);
	floorManager->attachComponent(floorHandler);
	this->registerObject(floorManager);

	EmptyGameObject* hammerManager = new EmptyGameObject("Hammer Manager");
	HammerHandler* hammerHandler = new HammerHandler(6, "HammerHandler", hammerManager);
	ladderManager->attachComponent(hammerHandler);
	this->registerObject(hammerManager);


	GameScreen* ui = new GameScreen("GameScreen");
	this->registerObject(ui);

	Border* lowerBorder = new Border("Border");
	lowerBorder->setPosition(1920/2, 2000);
	this->registerObject(lowerBorder);

	Border* dkBorder = new Border("Border");
	dkBorder->setPosition(490, 220);
	dkBorder->getTransformable()->setScale(0.08f, 2.2f);
	this->registerObject(dkBorder);

	Border* paulineBorder = new Border("Pauline");
	paulineBorder->setPosition(1200, 50);
	paulineBorder->getTransformable()->setScale(0.04f, 2.2f);
	this->registerObject(paulineBorder);

	BGObject* pauline = new BGObject("Pauline");
	pauline->setPosition(1200, 60);
	this->registerObject(pauline);
	
	Player* player = new Player("Player");
	this->registerObject(player);
	player->getTransformable()->setPosition(630, 950);	
	player->setSpawnPosition(630, 950);
	
	DonkeyKong* dk = new DonkeyKong("DonkeyKong");
	this->registerObject(dk);
	dk->getTransformable()->setPosition(630, 215);

	// Spawn Floors
	//GameObjectPool* floorPool = ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::FLOOR_POOL_TAG);
	//for (int i = 0; i < 5; ++i)
	//{
	//	float y = 1000 - (i * 180); // Start at 1000 and decrease by 180 for each set
	//	for (int j = 0; j < 1; ++j)
	//	{
	//		// Alternates between (1920/2 + 150) and (1920/2 - 150)
	//		float x = (i % 2 == 0) ? (1920 / 2 - 40) : (1920 / 2 + 40);

	//		SpawnManager::getInstance()->setFloorSpawn(x, y);
	//		floorPool->requestPoolable();
	//	}
	//}

	//Spawn ladders
	//ladderPool = ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::LADDER_POOL_TAG);
	//SpawnManager::getInstance()->setLadderSpawn(1920 / 2, 500);
	//ladderPool->requestPoolable();

	// Spawn hammers
	//hammerPool = ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::HAMMER_POOL_TAG);
	//SpawnManager::getInstance()->setDestination(830, 950);
	//hammerPool->requestPoolable();
}

void Level1Scene::onUnloadResources()
{
	TextureManager::getInstance()->unloadAll();
}

sf::Vector2f Level1Scene::getDestination()
{
	return this->dest;
}