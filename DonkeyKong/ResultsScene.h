#pragma once

#include "AScene.h"
#include "GameObjectManager.h"

class ResultsScene : public AScene
{
public:
	ResultsScene();

	void onLoadResources();
	void onLoadObjects();

	void onUnloadResources();
};

