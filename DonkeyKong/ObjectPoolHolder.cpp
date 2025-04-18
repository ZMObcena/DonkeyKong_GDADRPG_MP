#include "ObjectPoolHolder.h"

const std::string ObjectPoolHolder::BARREL_POOL_TAG = "BarrelPool";
const std::string ObjectPoolHolder::FLOOR_POOL_TAG = "FloorPool";
const std::string ObjectPoolHolder::FIRE_POOL_TAG = "FirePool";
const std::string ObjectPoolHolder::HAMMER_POOL_TAG = "HammerPool";
const std::string ObjectPoolHolder::LADDER_POOL_TAG = "LadderPool";

ObjectPoolHolder* ObjectPoolHolder::sharedInstance = nullptr;

ObjectPoolHolder* ObjectPoolHolder::getInstance()
{
	if (sharedInstance == nullptr)
	{
		sharedInstance = new ObjectPoolHolder();
	}

	return sharedInstance;
}

void ObjectPoolHolder::registerObjectPool(GameObjectPool* pool)
{
	this->poolMap[pool->getTag()] = pool;
}

void ObjectPoolHolder::unregisterObjectPool(GameObjectPool* pool)
{
	this->poolMap.erase(pool->getTag());
	delete pool;
}

GameObjectPool* ObjectPoolHolder::getPool(std::string tag)
{
	return this->poolMap[tag];
}