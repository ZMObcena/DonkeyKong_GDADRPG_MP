#include "Barrel.h"
#include "PhysicsManager.h"
#include "Level1Scene.h"
#include "BarrelMovement.h"
#include "DonkeyKong.h"
#include "ObjectPoolHolder.h"
#include "FloorManager.h"

Barrel::Barrel(std::string name) : APoolable(name), CollisionListener()
{
	this->name = name;
}

Barrel::~Barrel()
{

}

void Barrel::initialize()
{
	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*TextureManager::getInstance()->getTexture("Barrel"));
	sf::Vector2u textureSize = sprite->getTexture()->getSize();
	this->sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);
	this->sprite->setTextureRect(TextureManager::getInstance()->getSpriteRect("Barrel", 1));
	this->sprite->setScale(2.f, 2.f);
	sf::FloatRect bounds = sprite->getLocalBounds();
	this->sprite->setOrigin(bounds.width / 2, bounds.height / 2);

	BarrelMovement* movement = new BarrelMovement(this->name + " Movement");
	this->attachComponent(movement);

	Renderer* renderer = new Renderer(this->name + " Renderer");
	renderer->assignDrawable(sprite);
	this->attachComponent(renderer);

	this->collider = new Collider(this->name + " Collider");
	this->collider->setOffset(this->sprite->getLocalBounds());
	this->collider->assignListener(this);
	this->attachComponent(this->collider);

	//this->setPosition(730, 248);
	//this->setPosition(730, 950);

}

void Barrel::setSpawnPosition(float x, float y)
{
	this->setPosition(x, y);
}

void Barrel::onRelease()
{
	PhysicsManager::getInstance()->untrackObject(this->collider);
}

void Barrel::onActivate()
{
	if (collider == nullptr)
	{
		std::cout << this->name << " collider is null \n";
	}

	this->setPosition(720, 250);
	PhysicsManager::getInstance()->trackObject(this->collider);
}

APoolable* Barrel::clone()
{
	APoolable* copyObj = new Barrel(this->name);
	return copyObj;
}

void Barrel::onCollisionEnter(AGameObject* object)
{
	if (object->getName() == "Player")
	{

	}

	if (object->getName() == "Floor")
	{
		this->onFloor = true;
	}

	std::cout << this->name + " entered " + object->getName() << std::endl;
}

void Barrel::onCollisionExit(AGameObject* object)
{
	if (object->getName() == "Floor")
	{
		this->onFloor = false;

	}

	std::cout << this->name + " exited " + object->getName() << std::endl;
}

bool Barrel::isOnFloor() { return this->onFloor;  }

float Barrel::getSpeed() { return this->barrelSpeed;  }