#pragma once

#include "AScene.h"
#include "GameObjectManager.h"
#include "EmptyGameObject.h"

class Level2Scene : public AScene
{
public:
	Level2Scene();

	void onLoadResources();
	void onLoadObjects();

	void onUnloadResources();
};

