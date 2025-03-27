#include "Floor.h"
#include "PhysicsManager.h"

Floor::Floor(std::string name) : AGameObject(name), CollisionListener()
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
	sprite->setScale(3.0f, 3.0f);

	Renderer* renderer = new Renderer(this->name + " Renderer");
	renderer->assignDrawable(sprite);
	this->attachComponent(renderer);

	Collider* collider = new Collider(this->name + " Collider");
	collider->setOffset(sprite->getGlobalBounds());
	collider->assignListener(this);
	this->attachComponent(collider);
	PhysicsManager::getInstance()->trackObject(collider);
}

void Floor::onCollisionEnter(AGameObject* object)
{

}

void Floor::onCollisionExit(AGameObject* object)
{

}