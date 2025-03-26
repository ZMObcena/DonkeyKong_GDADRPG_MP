#include "EnemySwarmHandler.h"
#include "GameObjectPool.h"
#include "ObjectPoolHolder.h"
#include "Barrel.h"
#include <iostream>

EnemySwarmHandler::EnemySwarmHandler(int numEnemies, std::string name, AGameObject* parent) : AComponent(name, Script)
{
	this->pool = new GameObjectPool(
		ObjectPoolHolder::ENEMY_POOL_TAG,
		numEnemies,
		new Barrel("enemy"),
		parent);
	pool->initialize();
	ObjectPoolHolder::getInstance()->registerObjectPool(pool);
}

EnemySwarmHandler::~EnemySwarmHandler()
{
	delete this->pool;
}

void EnemySwarmHandler::perform()
{
	GameObjectPool* enemyPool = ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::ENEMY_POOL_TAG);
	this->ticks += this->deltaTime.asSeconds();

	if (this->ticks > SPAWN_INTERVAL)
	{
		this->ticks = 0.0f;
		enemyPool->requestPoolable();
	}
}