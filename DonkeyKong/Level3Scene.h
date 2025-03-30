#pragma once

#include "AScene.h"
#include "GameObjectManager.h"
#include "EmptyGameObject.h"

class Level3Scene : public AScene
{
public:
	Level3Scene();

	void onLoadResources();
	void onLoadObjects();

	void onUnloadResources();
};

