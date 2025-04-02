#include "HammerHandler.h"
#include "Hammer.h"
#include "ObjectPoolHolder.h"
#include "LevelManager.h"
#include "SpawnManager.h"
#include <iostream>

HammerHandler::HammerHandler(int num, std::string name, AGameObject* parent) : AComponent(name, Script)
{
	this->pool = new GameObjectPool(
		ObjectPoolHolder::HAMMER_POOL_TAG,
		num,
		new Hammer("Hammer"),
		parent);

	this->pool->initialize();
	ObjectPoolHolder::getInstance()->registerObjectPool(this->pool);
}

HammerHandler::~HammerHandler()
{
	delete this->pool;
}

void HammerHandler::perform()
{
	int level = LevelManager::getInstance()->getLevel();
	bool proceed = LevelManager::getInstance()->goNextLevel();

	if (level == 1 && proceed)
	{
		SpawnManager::getInstance()->setHammerSpawn(450, 530);
		this->pool->requestPoolable();

		SpawnManager::getInstance()->setHammerSpawn(1400, 700);
		this->pool->requestPoolable();

		SpawnManager::getInstance()->setHammerSpawn(1920 / 2 , 350);
		this->pool->requestPoolable();
	}

	else if (level == 2 && proceed)
	{
		SpawnManager::getInstance()->setHammerSpawn(1920 / 2 - 40, 350);
		this->pool->requestPoolable();
	}

	else if (level == 3 && proceed)
	{
		SpawnManager::getInstance()->setHammerSpawn(450, 530);
		this->pool->requestPoolable();

		SpawnManager::getInstance()->setHammerSpawn(1400, 700);
		this->pool->requestPoolable();

		SpawnManager::getInstance()->setHammerSpawn(1920 / 2, 350);
		this->pool->requestPoolable();
	}
}

