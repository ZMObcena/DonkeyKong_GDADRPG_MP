#pragma once
#include "AComponent.h"
#include "GameObjectPool.h"

class LadderHandler : public AComponent
{
public:
	LadderHandler(int num, std::string name, AGameObject* parent);
	~LadderHandler();
	void perform();

private:
	GameObjectPool* pool;

};

