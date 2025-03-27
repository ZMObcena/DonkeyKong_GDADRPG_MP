#pragma once

#include "AScene.h"
#include "GameObjectManager.h"

class MainMenuScene : public AScene
{
public:
	MainMenuScene();

	void onLoadResources();
	void onLoadObjects();

	void onUnloadResources();
};

