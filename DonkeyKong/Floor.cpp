#include "Floor.h"
#include "PhysicsManager.h"
#include "LevelManager.h"
#include "SpawnManager.h"

Floor::Floor(std::string name) : APoolable(name), CollisionListener()
{
	this->name = name;
}

Floor::~Floor()
{
	std::cout << "Floor gone\n";
}

void Floor::initialize()
{
	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*TextureManager::getInstance()->getTexture("Floor"));
	sf::Vector2u textureSize = sprite->getTexture()->getSize();
	this->sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);
	this->sprite->setScale(65.f, 2.f);
	sf::FloatRect bounds = sprite->getLocalBounds();
	this->sprite->setOrigin(bounds.width / 2, bounds.height / 2);

	Renderer* renderer = new Renderer(this->name + " Renderer");
	renderer->assignDrawable(this->sprite);
	this->attachComponent(renderer);

	this->collider = new Collider(this->name + " Collider");
	collider->setOffset(this->sprite->getGlobalBounds());
	collider->assignListener(this);
	this->attachComponent(collider);

}

void Floor::setSpawnPosition(float x, float y)
{
	this->setPosition(x, y);
}

void Floor::onRelease()
{
	std::cout << "Floor gang\n";
	PhysicsManager::getInstance()->untrackObject(this->collider);
}

void Floor::onActivate()
{
	if (LevelManager::getInstance()->getLevel() == 3)
	{
		this->sprite->setColor(sf::Color::Blue);
	}
	else
	{
		this->sprite->setColor(sf::Color::White); // default color
	}
	sf::Vector2f spawn = SpawnManager::getInstance()->getFloorSpawn();
	this->setPosition(spawn.x, spawn.y);

	spawn = SpawnManager::getInstance()->getScale();
	this->sprite->setScale(spawn.x, spawn.y);

	sf::FloatRect bounds = sprite->getLocalBounds();
	this->sprite->setOrigin(bounds.width / 2, bounds.height / 2);
	this->collider->setOffset(this->sprite->getGlobalBounds());

	PhysicsManager::getInstance()->trackObject(collider);
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