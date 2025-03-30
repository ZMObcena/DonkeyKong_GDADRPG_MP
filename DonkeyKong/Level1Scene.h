#pragma once

#include "AScene.h"
#include "GameObjectManager.h"
#include "EmptyGameObject.h"

class Level1Scene : public AScene
{
public:
	Level1Scene();

	void onLoadResources();
	void onLoadObjects();

	void onUnloadResources();
};

