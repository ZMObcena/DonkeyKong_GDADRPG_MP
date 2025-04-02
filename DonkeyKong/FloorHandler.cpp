#include "FloorHandler.h"
#include "Floor.h"
#include "ObjectPoolHolder.h"
#include "LevelManager.h"
#include "SpawnManager.h"
#include <iostream>

FloorHandler::FloorHandler(int numFloor, std::string name, AGameObject* parent) : AComponent(name, Script)
{
	this->floorPool = new GameObjectPool(
		ObjectPoolHolder::FLOOR_POOL_TAG,
		numFloor,
		new Floor("Floor"),
		parent);

	this->floorPool->initialize();
	ObjectPoolHolder::getInstance()->registerObjectPool(this->floorPool);
}

FloorHandler::~FloorHandler()
{
	delete this->floorPool;
}

void FloorHandler::perform()
{
	int level = LevelManager::getInstance()->getLevel();
	bool proceed = LevelManager::getInstance()->goNextLevel();
	GameObjectPool* floorPool = ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::FLOOR_POOL_TAG);

	if (level == 1 && proceed)
	{
		LevelManager::getInstance()->proceedToNextLevel(false);

		floorPool->requestPoolable();

		for (int i = 0; i < 5; ++i)
		{
			float y = 1000 - (i * 180); // Start at 1000 and decrease by 180 for each set
			for (int j = 0; j < 1; ++j)
			{
				// Alternates between (1920/2 + 150) and (1920/2 - 150)
				float x = (i % 2 == 0) ? (1920 / 2 - 40) : (1920 / 2 + 40);

				SpawnManager::getInstance()->setFloorSpawn(x, y, 65.0f, 2.0f);
				floorPool->requestPoolable();
			}
		}

		SpawnManager::getInstance()->setFloorSpawn(1200, 100, 10.0f, 2.0f);
		floorPool->requestPoolable();
	}

	if (level == 2 && proceed)
	{
		LevelManager::getInstance()->proceedToNextLevel(false);
		
		// 1st floor
		SpawnManager::getInstance()->setFloorSpawn(600, 1000, 5.0f, 2.0f);
		floorPool->requestPoolable();

		SpawnManager::getInstance()->setFloorSpawn(755, 1000, 5.0f, 2.0f);
		floorPool->requestPoolable();

		SpawnManager::getInstance()->setFloorSpawn(910, 1000, 5.0f, 2.0f);
		floorPool->requestPoolable();

		SpawnManager::getInstance()->setFloorSpawn(1065, 1000, 5.0f, 2.0f);
		floorPool->requestPoolable();

		SpawnManager::getInstance()->setFloorSpawn(1220, 1000, 5.0f, 2.0f);
		floorPool->requestPoolable();


		// 2nd floor
		SpawnManager::getInstance()->setFloorSpawn(600, 820, 10.0f, 2.0f);
		floorPool->requestPoolable();

		SpawnManager::getInstance()->setFloorSpawn(1920/2 -40, 820, 8.0f, 2.0f);
		floorPool->requestPoolable();

		SpawnManager::getInstance()->setFloorSpawn(1220, 820, 10.0f, 2.0f);
		floorPool->requestPoolable();

		// 3rd floor
		SpawnManager::getInstance()->setFloorSpawn(600, 640, 16.0f, 2.0f);
		floorPool->requestPoolable();

		SpawnManager::getInstance()->setFloorSpawn(1220, 640, 16.0f, 2.0f);
		floorPool->requestPoolable();

		SpawnManager::getInstance()->setFloorSpawn(1920 / 2 - 40, 640, 16.0f, 2.0f);
		floorPool->requestPoolable();

		// 4th floor
		SpawnManager::getInstance()->setFloorSpawn(600, 460, 35.0f, 2.0f);
		floorPool->requestPoolable();

		SpawnManager::getInstance()->setFloorSpawn(1220, 460, 35.0f, 2.0f);
		floorPool->requestPoolable();

		//Donkey Kong platform
		SpawnManager::getInstance()->setFloorSpawn(1920 / 2 - 40, 280, 65.0f, 2.0f);
		floorPool->requestPoolable();

		// Pauline platform
		SpawnManager::getInstance()->setFloorSpawn(1200, 100, 10.0f, 2.0f);
		floorPool->requestPoolable();
	}

	if (level == 3 && proceed)
	{
		LevelManager::getInstance()->proceedToNextLevel(false);

		floorPool->requestPoolable();

		for (int i = 0; i < 5; ++i)
		{
			float y = 1000 - (i * 180); // Start at 1000 and decrease by 180 for each set
			for (int j = 0; j < 1; ++j)
			{
				// Alternates between (1920/2 + 150) and (1920/2 - 150)
				float x = (i % 2 == 0) ? (1920 / 2 - 40) : (1920 / 2 + 40);

				SpawnManager::getInstance()->setFloorSpawn(x, y, 65.0f, 2.0f);
				floorPool->requestPoolable();
			}
		}

		SpawnManager::getInstance()->setFloorSpawn(1200, 100, 10.0f, 2.0f);
		floorPool->requestPoolable();
	}
}