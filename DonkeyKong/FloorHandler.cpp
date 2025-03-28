#include "FloorHandler.h"
#include "ObjectPoolHolder.h"
#include "Floor.h"
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

	this->counter = 0;
}

FloorHandler::~FloorHandler()
{
	delete this->floorPool;
}

void FloorHandler::perform()
{

}