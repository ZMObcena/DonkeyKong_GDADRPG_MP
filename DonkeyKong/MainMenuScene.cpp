#include "MainMenuScene.h"
#include "MainMenuScreen.h"
#include <iostream>
#include "TextureManager.h"
#include "SceneManager.h"

MainMenuScene::MainMenuScene() : AScene("MainMenuScene") {}

void MainMenuScene::onLoadResources() 
{
	TextureManager::getInstance()->loadMainMenu();
}

void MainMenuScene::onLoadObjects() 
{
	MainMenuScreen* menuScreen = new MainMenuScreen("MainMenuScreen");
	this->registerObject(menuScreen);
}

void MainMenuScene::onUnloadResources() 
{
	TextureManager::getInstance()->unloadAll();
}
