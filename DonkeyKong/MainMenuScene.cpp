#include "MainMenuScene.h"
#include "MainMenuScreen.h"
#include <iostream>
#include "TextureManager.h"
#include "SceneManager.h"
#include "SFXManager.h"

MainMenuScene::MainMenuScene() : AScene("MainMenuScene") {}

void MainMenuScene::onLoadResources() 
{
	TextureManager::getInstance()->loadMainMenu();
}

void MainMenuScene::onLoadObjects() 
{
	SFXManager::getInstance()->stopPlaying("background");
	SFXManager::getInstance()->stopPlaying("results");
	SFXManager::getInstance()->stopPlaying("winner");
	SFXManager::getInstance()->playSound("intro");
	MainMenuScreen* menuScreen = new MainMenuScreen("MainMenuScreen");
	this->registerObject(menuScreen);
}

void MainMenuScene::onUnloadResources() 
{
	TextureManager::getInstance()->unloadAll();
}
