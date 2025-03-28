#include "FloorManager.h"

FloorManager* FloorManager::sharedInstance = nullptr;


void FloorManager::setDestination(float x, float y)
{
	this->destination.x = x;
	this->destination.y = y;
}

sf::Vector2f FloorManager::getDestination()
{
	return this->destination;
}


FloorManager* FloorManager::getInstance()
{
	if (sharedInstance == nullptr)
	{
		sharedInstance = new FloorManager();
	}
	return sharedInstance;
};