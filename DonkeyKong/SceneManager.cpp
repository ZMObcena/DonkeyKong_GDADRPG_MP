#include "SceneManager.h"
#include <iostream>

std::string SceneManager::MAIN_MENU_SCENE = "MainMenuScene";
std::string SceneManager::RESULTS_SCENE = "ResultsScene";
std::string SceneManager::LEVEL_1_SCENE = "Level1Scene";
std::string SceneManager::LEVEL_2_SCENE = "Level2Scene";
std::string SceneManager::LEVEL_3_SCENE = "Level3Scene";

SceneManager* SceneManager::sharedInstance = nullptr;

void SceneManager::registerScene(AScene* scene)
{
	std::cout << scene->getSceneName() << " registered! \n";
	this->storedScenes[scene->getSceneName()] = scene;
}

void SceneManager::checkLoadScene()
{
	if (this->isLoading)
	{
		this->unloadScene();
		this->activeScene = this->storedScenes[this->toLoadSceneName];
		this->activeScene->onLoadResources();
		this->activeScene->onLoadObjects();
		this->isLoading = false;
	}
}

void SceneManager::loadScene(std::string name)
{
	this->isLoading = true;
	this->toLoadSceneName = name;
}

void SceneManager::unloadScene()
{
	if (this->activeScene != nullptr)
	{
		this->activeScene->onUnloadObjects();
		this->activeScene->onUnloadResources();
	}
}

bool SceneManager::isSceneLoaded(std::string name)
{
	return this->activeScene->getSceneName() == name;
}

SceneManager* SceneManager::getInstance()
{
	if (sharedInstance == nullptr)
	{
		sharedInstance = new SceneManager();
	}

	return sharedInstance;
}