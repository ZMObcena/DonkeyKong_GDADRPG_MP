#include "LevelManager.h"
#include "SceneManager.h"
#include "SFXManager.h"

LevelManager* LevelManager::sharedInstance = nullptr;

void LevelManager::reset()
{
	this->level = 1;
	this->score = 0;
	this->lives = 3;
}

void LevelManager::increaseLevel()
{
	this->level++;
	this->checkLevel();
}

void LevelManager::checkLevel()
{
	if (this->level > 3)
	{
		SFXManager::getInstance()->playSound("win2");
		SceneManager::getInstance()->loadScene(SceneManager::RESULTS_SCENE);
	}
	else
	{
		SceneManager::getInstance()->loadScene(SceneManager::RESULTS_SCENE);
	}

}

void LevelManager::setLevel(int level)
{
	this->level = level;
}

int LevelManager::getLevel() { return this->level; }

void LevelManager::setScore(int score)
{
	this->score = score;
}

int LevelManager::getLives() { return this->lives; }

void LevelManager::setLives(int lives)
{
	this->lives = lives;
}

int LevelManager::getScore() { return this->score; }

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