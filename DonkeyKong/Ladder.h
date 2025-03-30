#pragma once

#include "CollisionListener.h"
#include "Collider.h"
#include "APoolable.h"
#include "TextureManager.h"

class Ladder : public APoolable, public CollisionListener
{
public:
	Ladder(std::string name);
	~Ladder();

	void initialize();
	void setSpawnPosition(float x, float y);
	void onRelease();
	void onActivate();
	APoolable* clone();

	void onCollisionEnter(AGameObject* object);
	void onCollisionExit(AGameObject* object);

private:
	Collider* collider;
};

