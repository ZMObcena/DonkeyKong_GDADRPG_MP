#pragma once

#include "APoolable.h"
#include "CollisionListener.h"
#include "Collider.h"

class Fire : public APoolable, CollisionListener
{
public:
	Fire(std::string name);
	~Fire();

	void initialize();
	void setSpawnPosition(float x, float y);
	void onRelease();
	void onActivate();
	APoolable* clone();

	void onCollisionEnter(AGameObject* object);
	void onCollisionExit(AGameObject* object);

	bool isOnFloor();
	bool isOnLadder();
	float getSpeed();

private:
	Collider* collider;
	bool onLadder;
	bool onFloor;
	const float fireSpeed = 50.0f;
};

