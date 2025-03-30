#include "ResultsScene.h"
#include "ResultsScreen.h"
#include <iostream>
#include "TextureManager.h"
#include "SceneManager.h"

ResultsScene::ResultsScene() : AScene("ResultsScene") {}

void ResultsScene::onLoadResources()
{
	//TextureManager::getInstance()->loadMainMenu();
}

void ResultsScene::onLoadObjects()
{
	ResultsScreen* resultsScreen = new ResultsScreen("ResultsScreen");
	this->registerObject(resultsScreen);
}

void ResultsScene::onUnloadResources()
{
	TextureManager::getInstance()->unloadAll();
}
