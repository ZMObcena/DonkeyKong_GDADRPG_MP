#include "ResultsScene.h"
#include "ResultsScreen.h"
#include <iostream>
#include "TextureManager.h"
#include "SceneManager.h"
#include "UIText.h"
#include "UIData.h"
#include "UIManager.h"
#include "LevelManager.h"

ResultsScene::ResultsScene() : AScene("ResultsScene") {}

void ResultsScene::onLoadResources()
{
	//TextureManager::getInstance()->loadMainMenu();
}

void ResultsScene::onLoadObjects()
{
	ResultsScreen* resultsScreen = new ResultsScreen("ResultsScreen");
	this->registerObject(resultsScreen);

	UIText* scoreText = new UIText("ScoreText");
	this->registerObject(scoreText);
	scoreText->setPosition(1920 / 2, 300);
	scoreText->setSize(60);
	scoreText->setText("0");
	UIData* scoreData = UIManager::getInstance()->storeData(scoreText->getName());
	scoreData->bindUIText(scoreText);
	scoreData->putInt(UIManager::SCORE_UI_KEY, LevelManager::getInstance()->getScore());
	scoreData->refreshTextFromData(scoreText->getName(), UIManager::SCORE_UI_KEY, "SCORE:");

	UIText* lifeText = new UIText("LifeText");
	this->registerObject(lifeText);
	lifeText->setPosition(1920 / 2, 500);
	lifeText->setSize(60);
	lifeText->setText("LIVES:3");
	UIData* lifeData = UIManager::getInstance()->storeData(lifeText->getName());
	lifeData->bindUIText(lifeText);
	lifeData->putInt(UIManager::LIFE_UI_KEY, LevelManager::getInstance()->getLives());
	lifeData->refreshTextFromData(lifeText->getName(), UIManager::LIFE_UI_KEY, "LIVES:");

	UIText* levelText = new UIText("LevelText");
	this->registerObject(levelText);
	levelText->setPosition(1920 / 2, 100);
	levelText->setSize(60);
	levelText->setText("LEVEL:");
	UIData* levelData = UIManager::getInstance()->storeData(levelText->getName());
	levelData->bindUIText(levelText);
	levelData->putInt(UIManager::LEVEL_UI_KEY, LevelManager::getInstance()->getLevel() - 1);
	levelData->refreshTextFromData(levelText->getName(), UIManager::LEVEL_UI_KEY, "LEVEL:");

	if (LevelManager::getInstance()->getLives() < 0)
	{
		lifeText->setText("LIVES:0");
	}

}

void ResultsScene::onUnloadResources()
{
	TextureManager::getInstance()->unloadAll();
}
