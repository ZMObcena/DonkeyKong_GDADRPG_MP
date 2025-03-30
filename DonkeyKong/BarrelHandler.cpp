#include "BarrelHandler.h"
#include "Barrel.h"
#include "ObjectPoolHolder.h"
#include "LevelManager.h"
#include "SpawnManager.h"

BarrelHandler::BarrelHandler(int numBarrel, std::string name, AGameObject* parent) : AComponent(name, Script)
{
	this->barrelPool = new GameObjectPool(
		ObjectPoolHolder::BARREL_POOL_TAG,
		numBarrel,
		new Barrel("Barrel"),
		parent);

	this->barrelPool->initialize();
	ObjectPoolHolder::getInstance()->registerObjectPool(this->barrelPool);
}

BarrelHandler::~BarrelHandler()
{
	delete this->barrelPool;
}

void BarrelHandler::perform()
{
	int level = LevelManager::getInstance()->getLevel();
	bool proceed = LevelManager::getInstance()->goNextLevel();

	if (level == 1)
	{
		SpawnManager::getInstance()->setBarrelSpawn(720, 250);
	}
	
	else if (level == 2)
	{
		SpawnManager::getInstance()->setBarrelSpawn(720, 250);
	}

	else if (level == 3)
	{
		SpawnManager::getInstance()->setBarrelSpawn(720, 250);
	}
}