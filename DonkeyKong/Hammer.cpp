#include "Hammer.h"
#include "PhysicsManager.h"
#include "ObjectPoolHolder.h"
#include "FloorManager.h"

Hammer::Hammer(std::string name) : APoolable(name), CollisionListener()
{
	this->name = name;
}

Hammer::~Hammer()
{

}

void Hammer::initialize()
{
	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*TextureManager::getInstance()->getTexture("Hammer"));
	sf::Vector2u textureSize = sprite->getTexture()->getSize();
	this->sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);
	this->sprite->setScale(3.f, 3.f);
	sf::FloatRect bounds = sprite->getLocalBounds();
	this->sprite->setOrigin(bounds.width / 2, bounds.height / 2);

	Renderer* renderer = new Renderer(this->name + " Renderer");
	renderer->assignDrawable(sprite);
	this->attachComponent(renderer);

	this->collider = new Collider(this->name + " Collider");
	this->collider->setOffset(this->sprite->getLocalBounds());
	this->collider->assignListener(this);
	this->attachComponent(this->collider);
}

void Hammer::setSpawnPosition(float x, float y)
{
	this->setPosition(x, y);
}

void Hammer::onRelease()
{
	PhysicsManager::getInstance()->untrackObject(this->collider);
}

void Hammer::onActivate()
{
	sf::Vector2f dest = FloorManager::getInstance()->getDestination();
	this->setPosition(dest.x, dest.y);

	PhysicsManager::getInstance()->trackObject(this->collider);
}

APoolable* Hammer::clone()
{
	APoolable* copyObj = new Hammer(this->name);
	return copyObj;
}

void Hammer::onCollisionEnter(AGameObject* object)
{
	if (object->getName() == "Player")
	{
		GameObjectPool* pool = ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::HAMMER_POOL_TAG);
		pool->releasePoolable((APoolable*)this);
	}
}

void Hammer::onCollisionExit(AGameObject* object)
{

}
