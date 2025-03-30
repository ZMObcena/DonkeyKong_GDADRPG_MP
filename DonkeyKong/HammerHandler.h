#pragma once
#include "AComponent.h"
#include "GameObjectPool.h"

class HammerHandler : public AComponent
{
public:
	HammerHandler(int num, std::string name, AGameObject* parent);
	~HammerHandler();
	void perform();

private:
	GameObjectPool* pool;
};

