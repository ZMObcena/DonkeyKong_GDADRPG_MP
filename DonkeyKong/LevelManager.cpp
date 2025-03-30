#include "LevelManager.h"
#include "SceneManager.h"

LevelManager* LevelManager::sharedInstance = nullptr;

void LevelManager::setLevel(int level)
{
	if (this->level + level > 3)
	{
		this->level = 1;
		SceneManager::getInstance()->loadScene(SceneManager::RESULTS_SCENE);
	}
	else if (this->level + level == 3)
	{
		this->level += level;
		SceneManager::getInstance()->loadScene(SceneManager::LEVEL_3_SCENE);
		this->proceedToNextLevel(true);
	}
	else if (this->level + level == 2)
	{
		this->level += level;
		SceneManager::getInstance()->loadScene(SceneManager::LEVEL_2_SCENE);
		this->proceedToNextLevel(true);
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