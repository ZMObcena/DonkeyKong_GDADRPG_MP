#include "Floor.h"
#include "PhysicsManager.h"
#include "Level1Scene.h"
#include "FloorManager.h"

Floor::Floor(std::string name) : APoolable(name), CollisionListener()
{
	this->name = name;
}

Floor::~Floor()
{

}

void Floor::initialize()
{
	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*TextureManager::getInstance()->getTexture("Floor"));
	sf::Vector2u textureSize = sprite->getTexture()->getSize();
	sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);
	sprite->setScale(65.f, 2.f);
	sf::FloatRect bounds = sprite->getLocalBounds();
	sprite->setOrigin(bounds.width / 2, bounds.height / 2);

	Renderer* renderer = new Renderer(this->name + " Renderer");
	renderer->assignDrawable(sprite);
	this->attachComponent(renderer);

	Collider* collider = new Collider(this->name + " Collider");
	collider->setOffset(sprite->getGlobalBounds());
	collider->assignListener(this);
	this->attachComponent(collider);
	PhysicsManager::getInstance()->trackObject(collider);
}

void Floor::setSpawnPosition(float x, float y)
{
	this->setPosition(x, y);
}

void Floor::onRelease()
{

}

void Floor::onActivate()
{
	sf::Vector2f dest = FloorManager::getInstance()->getDestination();
	this->setPosition(dest.x, dest.y);
}

APoolable* Floor::clone()
{
	APoolable* copyObj = new Floor(this->name);
	return copyObj;
}

void Floor::onCollisionEnter(AGameObject* object)
{

}

void Floor::onCollisionExit(AGameObject* object)
{

}