#pragma once
#include "AComponent.h"
#include "GameObjectPool.h"
#include <cstdlib>

class FireHandler : public AComponent
{
public:
	FireHandler(int num, std::string name, AGameObject* parent);
	~FireHandler();
	void perform();

private:
	GameObjectPool* pool;
	float ticks;
	int yPositions[4] = { 970, 790, 610, 430 };
};

