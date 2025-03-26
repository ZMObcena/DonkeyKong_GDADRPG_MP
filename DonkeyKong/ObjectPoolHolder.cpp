#include "ObjectPoolHolder.h"

const std::string ObjectPoolHolder::ENEMY_POOL_TAG = "EnemyPool";

ObjectPoolHolder* ObjectPoolHolder::sharedInstance = nullptr;

ObjectPoolHolder* ObjectPoolHolder::getInstance()
{
	if (sharedInstance == nullptr)
	{
		sharedInstance = new ObjectPoolHolder();
	}

	return sharedInstance;
}

void ObjectPoolHolder::registerObjectPool(GameObjectPool* pPool)
{
	this->poolMap[pPool->getTag()] = pPool;
}

void ObjectPoolHolder::unregisterObjectPool(GameObjectPool* pPool) 
{
	this->poolMap.erase(pPool->getTag());
	delete pPool;
}

GameObjectPool* ObjectPoolHolder::getPool(std::string tag)
{
	return this->poolMap[tag];
}
