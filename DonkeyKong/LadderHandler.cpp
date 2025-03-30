#include "LadderHandler.h"
#include "Ladder.h"
#include "ObjectPoolHolder.h"
#include "LevelManager.h"
#include "SpawnManager.h"

LadderHandler::LadderHandler(int num, std::string name, AGameObject* parent) : AComponent(name, Script)
{
	this->pool = new GameObjectPool(
		ObjectPoolHolder::LADDER_POOL_TAG,
		num,
		new Ladder("Ladder"),
		parent);

	this->pool->initialize();
	ObjectPoolHolder::getInstance()->registerObjectPool(this->pool);
}

LadderHandler::~LadderHandler()
{
	delete this->pool;
}

void LadderHandler::perform()
{
	int level = LevelManager::getInstance()->getLevel();
	bool proceed = LevelManager::getInstance()->goNextLevel();

	int offset = 170;

	if (level == 1 && proceed)
	{
		SpawnManager::getInstance()->setLadderSpawn(580 , 873);
		this->pool->requestPoolable();

		SpawnManager::getInstance()->setLadderSpawn(1240, 873);
		this->pool->requestPoolable();

		SpawnManager::getInstance()->setLadderSpawn(1920 / 2, 863 - offset);
		this->pool->requestPoolable();

		SpawnManager::getInstance()->setLadderSpawn(580, 853 - offset * 2);
		this->pool->requestPoolable();

		SpawnManager::getInstance()->setLadderSpawn(1240, 853 - offset * 2);
		this->pool->requestPoolable();		
		
		SpawnManager::getInstance()->setLadderSpawn(1360, 843 - offset * 3);
		this->pool->requestPoolable();

		SpawnManager::getInstance()->setLadderSpawn(1140, 843 - offset * 4);
		this->pool->requestPoolable();

		SpawnManager::getInstance()->setLadderSpawn(1260, 843 - offset * 4);
		this->pool->requestPoolable();
	}

	else if (level == 2 && proceed)
	{

	}

	else if (level == 3 && proceed)
	{

	}
}