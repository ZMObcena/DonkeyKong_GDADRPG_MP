#pragma once
#include "AComponent.h"
#include "GameObjectPool.h"

class FloorHandler : public AComponent
{
public:
	FloorHandler(int numFloor, std::string name, AGameObject* parent);
	~FloorHandler();
	void perform();

private:
	GameObjectPool* floorPool;
	float ticks;
	int counter;
};

