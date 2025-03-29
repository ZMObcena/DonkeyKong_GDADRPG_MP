#pragma once

#include "CollisionListener.h"
#include "Collider.h"
#include "APoolable.h"
#include "TextureManager.h"

class Floor : public APoolable, public CollisionListener
{
public:
	Floor(std::string name);
	~Floor();
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

