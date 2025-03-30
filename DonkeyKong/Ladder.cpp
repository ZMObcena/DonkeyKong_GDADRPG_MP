#include "Ladder.h"


#include "PhysicsManager.h"
#include "Level1Scene.h"
#include "ObjectPoolHolder.h"
#include "SpawnManager.h"

Ladder::Ladder(std::string name) : APoolable(name), CollisionListener()
{
	this->name = name;
}

Ladder::~Ladder()
{

}

void Ladder::initialize()
{
	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*TextureManager::getInstance()->getTexture("Ladder"));
	sf::Vector2u textureSize = sprite->getTexture()->getSize();
	this->sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);
	this->sprite->setScale(1.5f, 1.25f);
	sf::FloatRect bounds = this->sprite->getLocalBounds();
	this->sprite->setOrigin(bounds.width / 2, bounds.height / 2);

	Renderer* renderer = new Renderer(this->name + " Renderer");
	renderer->assignDrawable(this->sprite);
	this->attachComponent(renderer);

	this->collider = new Collider(this->name + " Collider");
	this->collider->setOffset(this->sprite->getGlobalBounds());
	this->collider->assignListener(this);
	this->attachComponent(this->collider);
}

void Ladder::setSpawnPosition(float x, float y)
{
	this->setPosition(x, y);
}

void Ladder::onRelease()
{
	PhysicsManager::getInstance()->untrackObject(this->collider);
}

void Ladder::onActivate()
{
	sf::Vector2f dest = SpawnManager::getInstance()->getLadderSpawn();
	this->setPosition(dest.x, dest.y);

	PhysicsManager::getInstance()->trackObject(this->collider);
}

APoolable* Ladder::clone()
{
	APoolable* copyObj = new Ladder(this->name);
	return copyObj;
}

void Ladder::onCollisionEnter(AGameObject* object)
{

}

void Ladder::onCollisionExit(AGameObject* object)
{

}
