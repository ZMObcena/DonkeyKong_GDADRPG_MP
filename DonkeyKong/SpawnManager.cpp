#include "SpawnManager.h"

SpawnManager* SpawnManager::sharedInstance = nullptr;

void SpawnManager::setLadderSpawn(float x, float y)
{
	this->ladderSpawn.x = x;
	this->ladderSpawn.y = y;
}

void SpawnManager::setFloorSpawn(float x, float y)
{
	this->floorSpawn.x = x;
	this->floorSpawn.y = y;
}

void SpawnManager::setFloorSpawn(float x, float y, float scaleX, float scaleY)
{
	this->floorSpawn.x = x;
	this->floorSpawn.y = y;
	this->scale.x = scaleX;
	this->scale.y = scaleY;
}

void SpawnManager::setBarrelSpawn(float x, float y)
{
	this->barrelSpawn.x = x;
	this->barrelSpawn.y = y;
}

void SpawnManager::setFireSpawn(float x, float y)
{
	this->fireSpawn.x = x;
	this->fireSpawn.y = y;
}

void SpawnManager::setDKSpawn(float x, float y)
{
	this->dkSpawn.x = x;
	this->dkSpawn.y = y;
}

void SpawnManager::setPlayerSpawn(float x, float y)
{
	this->playerSpawn.x = x;
	this->playerSpawn.y = y;
}

void SpawnManager::setHammerSpawn(float x, float y)
{
	this->hammerSpawn.x = x;
	this->hammerSpawn.y = y;
}

sf::Vector2f SpawnManager::getScale() { return this->scale; }

sf::Vector2f SpawnManager::getFloorSpawn() { return this->floorSpawn; }

sf::Vector2f SpawnManager::getLadderSpawn() { return this->ladderSpawn; }

sf::Vector2f SpawnManager::getBarrelSpawn() { return this->barrelSpawn; }

sf::Vector2f SpawnManager::getFireSpawn() { return this->fireSpawn; }

sf::Vector2f SpawnManager::getDKSpawn() { return this->dkSpawn; }

sf::Vector2f SpawnManager::getPlayerSpawn() { return this->playerSpawn; }

sf::Vector2f SpawnManager::getHammerSpawn() { return this->hammerSpawn; }

SpawnManager* SpawnManager::getInstance()
{
	if (sharedInstance == nullptr)
	{
		sharedInstance = new SpawnManager();
	}
	return sharedInstance;
};