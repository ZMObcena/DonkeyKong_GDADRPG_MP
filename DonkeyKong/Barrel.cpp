#include "Barrel.h"

Barrel::Barrel(std::string name) : APoolable(name), CollisionListener()
{
	this->name = name;
}

Barrel::~Barrel()
{

}

void Barrel::initialize()
{
	this->collider = new Collider("BarrelCollider");
	this->collider->setOffset(sprite->getGlobalBounds());
	this->collider->assignListener(this);
	this->attachComponent(this->collider);
}

void Barrel::onActivate()
{
	PhysicsManager::getInstance()->trackObject(this->collider);
}

void Barrel::onRelease()
{
	PhysicsManager::getInstance()->untrackObject(this->collider);
}

APoolable* Barrel::clone()
{
	APoolable* copyObj = new Barrel(this->name);
	return copyObj;
}

void Barrel::onCollisionEnter(AGameObject* contact)
{
	if (contact->getName().find("") != std::string::npos)
	{
		GameObjectPool* enemyPool = ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::ENEMY_POOL_TAG);
		enemyPool->releasePoolable((APoolable*)this);
	}
}

void Barrel::onCollisionExit(AGameObject* contact)
{

}