#pragma once

#include "APoolable.h"
#include "AGameObject.h"
#include "CollisionListener.h"
#include "GameObjectPool.h"
#include "ObjectPoolHolder.h"
#include "PhysicsManager.h"

class Barrel : public APoolable, public CollisionListener
{
public:
	Barrel(std::string name);
	~Barrel();

	void initialize();
	void onRelease();
	void onActivate();
	APoolable* clone();

	void onCollisionEnter(AGameObject* object);
	void onCollisionExit(AGameObject* object);

private:
	sf::Sprite* sprite = new sf::Sprite();
	int counter = 0;

	const int SPAWN_RANGE = 300;

	Collider* collider;
};

