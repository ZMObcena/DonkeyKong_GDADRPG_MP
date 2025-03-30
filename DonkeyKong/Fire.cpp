#include "Fire.h"
#include "TextureManager.h"
#include "PhysicsManager.h"
#include "FireMovement.h"
#include "GameObjectPool.h"
#include "ObjectPoolHolder.h"

Fire::Fire(std::string name) : APoolable(name), CollisionListener()
{
	this->name = name;
}

Fire::~Fire()
{

}

void Fire::initialize()
{
	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*TextureManager::getInstance()->getTexture("Fire"));
	sf::Vector2u textureSize = sprite->getTexture()->getSize();
	this->sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);
	this->sprite->setTextureRect(TextureManager::getInstance()->getSpriteRect("Fire", 0));
	this->sprite->setScale(2.f, 2.f);
	sf::FloatRect bounds = sprite->getLocalBounds();
	this->sprite->setOrigin(bounds.width / 2, bounds.height / 2);

	FireMovement* movement = new FireMovement(this->name + " Movement");
	this->attachComponent(movement);

	Renderer* renderer = new Renderer(this->name + " Renderer");
	renderer->assignDrawable(this->sprite);
	this->attachComponent(renderer);

	this->collider = new Collider(this->name + " Collider");
	this->collider->setOffset(this->sprite->getLocalBounds());
	this->collider->assignListener(this);
	this->attachComponent(this->collider);
}

void Fire::setSpawnPosition(float x, float y)
{
	this->setPosition(x, y);
}

void Fire::onRelease()
{
	PhysicsManager::getInstance()->untrackObject(this->collider);
}

void Fire::onActivate()
{
	PhysicsManager::getInstance()->trackObject(this->collider);
}

APoolable* Fire::clone()
{
	APoolable* copyObj = new Fire(this->name);
	return copyObj;
}

void Fire::onCollisionEnter(AGameObject* object)
{
	if (object->getName() == "Player")
	{
		GameObjectPool* pool = ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::FIRE_POOL_TAG);
		pool->releasePoolable((APoolable*)this);
	}

	if (object->getName() == "Border")
	{
		GameObjectPool* pool = ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::FIRE_POOL_TAG);
		pool->releasePoolable((APoolable*)this);
	}

	if (object->getName() == "Floor")
	{
		this->onFloor = true;
	}

	std::cout << this->name + " entered " + object->getName() << std::endl;
}

void Fire::onCollisionExit(AGameObject* object)
{
	if (object->getName() == "Floor")
	{
		this->onFloor = false;
	}

	std::cout << this->name + " exited " + object->getName() << std::endl;
}

bool Fire::isOnFloor() { return this->onFloor; }

float Fire::getSpeed() { return this->fireSpeed; }