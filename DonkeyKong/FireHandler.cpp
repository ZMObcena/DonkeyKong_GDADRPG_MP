#include "FireHandler.h"
#include "Fire.h"
#include "ObjectPoolHolder.h"
#include "LevelManager.h"
#include "SpawnManager.h"
#include <iostream>
#include <random>

FireHandler::FireHandler(int num, std::string name, AGameObject* parent) : AComponent(name, Script)
{
	this->pool = new GameObjectPool(
		ObjectPoolHolder::FIRE_POOL_TAG,
		num,
		new Fire("Fire"),
		parent);

	this->pool->initialize();
	ObjectPoolHolder::getInstance()->registerObjectPool(this->pool);
}

FireHandler::~FireHandler()
{
	delete this->pool;
}

void FireHandler::perform()
{
	ticks += this->deltaTime.asSeconds();
	bool proceed = LevelManager::getInstance()->goNextLevel();
	GameObjectPool* pool = ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::FIRE_POOL_TAG);

	if (LevelManager::getInstance()->getLevel() == 3)
	{
		int randomIndex = rand() % 4;
		int randomY = yPositions[randomIndex];
	
		if (proceed)
		{
			SpawnManager::getInstance()->setFireSpawn(1920 / 2, randomY);
			this->pool->requestPoolable();
		}

		if (ticks >= 7)
		{
			SpawnManager::getInstance()->setFireSpawn(1920/2 , randomY);
			this->pool->requestPoolable();
			ticks = 0;
		}
	}

	//
}
