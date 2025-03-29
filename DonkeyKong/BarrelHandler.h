#pragma once

#include "AComponent.h"
#include "GameObjectPool.h"
class BarrelHandler : public AComponent
{
public:
	BarrelHandler(int numBarrel, std::string name, AGameObject* parent);
	~BarrelHandler();
	void perform();

private:
	GameObjectPool* barrelPool;
	float ticks;
};

