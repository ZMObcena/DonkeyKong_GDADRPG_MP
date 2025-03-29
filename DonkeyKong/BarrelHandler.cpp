#include "BarrelHandler.h"
#include "Barrel.h"
#include "ObjectPoolHolder.h"

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

}