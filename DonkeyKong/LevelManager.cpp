#include "LevelManager.h"
#include "SceneManager.h"

LevelManager* LevelManager::sharedInstance = nullptr;

void LevelManager::increaseLevel()
{
	this->level++;
	this->checkLevel();
}

void LevelManager::checkLevel()
{
	if (this->level > 3)
	{
		this->level = 1;
		SceneManager::getInstance()->loadScene(SceneManager::RESULTS_SCENE);
	}
	else if (this->level == 3)
	{
		this->proceedToNextLevel(true);
		SceneManager::getInstance()->loadScene(SceneManager::LEVEL_3_SCENE);
	}
	else if (this->level  == 2)
	{
		this->proceedToNextLevel(true);
		SceneManager::getInstance()->loadScene(SceneManager::LEVEL_2_SCENE);
	}
}

int LevelManager::getLevel() { return this->level; }

void LevelManager::proceedToNextLevel(bool proceed)
{
	this->nextLevel = proceed;
}

bool LevelManager::goNextLevel() { return this->nextLevel; }

LevelManager* LevelManager::getInstance()
{
	if (sharedInstance == nullptr)
	{
		sharedInstance = new LevelManager();
	}
	return sharedInstance;
};