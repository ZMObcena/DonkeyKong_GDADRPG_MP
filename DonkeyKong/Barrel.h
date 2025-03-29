#pragma once

#include "CollisionListener.h"
#include "Collider.h"
#include "APoolable.h"
#include "TextureManager.h"

class Barrel : public APoolable, public CollisionListener
{
public:
	Barrel(std::string name);
	~Barrel();

	void initialize();
	void setSpawnPosition(float x, float y);
	void onRelease();
	void onActivate();
	APoolable* clone();

	void onCollisionEnter(AGameObject* object);
	void onCollisionExit(AGameObject* object);

	bool isOnFloor();
	float getSpeed();

private:
	Collider* collider;
	bool onFloor;
	const float barrelSpeed = 100.0f;
};

