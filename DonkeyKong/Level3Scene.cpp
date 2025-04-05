#include "Level3Scene.h"

#include <iostream>
#include "TextureManager.h"
#include "SceneManager.h"
#include "PhysicsManager.h"
#include "GameObjectPool.h"
#include "ObjectPoolHolder.h"
#include "Player.h"
#include "DonkeyKong.h"
#include "Floor.h"
#include "FloorHandler.h"
#include "SpawnManager.h"
#include "BarrelHandler.h"
#include "LadderHandler.h"
#include "HammerHandler.h"
#include "FireHandler.h"
#include "GameScreen.h"
#include "Hammer.h"
#include "Border.h"
#include "Ladder.h"
#include "BGObject.h"
#include "LevelManager.h"
#include "UIData.h"
#include "UIManager.h"
#include "SFXManager.h"


Level3Scene::Level3Scene() : AScene("Level3Scene") {}

void Level3Scene::onLoadResources()
{
	//TextureManager::getInstance()->loadAll();
}

void Level3Scene::onLoadObjects()
{
	srand(time(nullptr));

	EmptyGameObject* holder = new EmptyGameObject("Physics Manager Holder");
	PhysicsManager::initialize("Physics Manager", holder);
	this->registerObject(holder);

	EmptyGameObject* barrelManager = new EmptyGameObject("Barrel Manager");
	BarrelHandler* barrelHandler = new BarrelHandler(100, "BarrelHandler", barrelManager);
	barrelManager->attachComponent(barrelHandler);
	this->registerObject(barrelManager);

	EmptyGameObject* fireManager = new EmptyGameObject("Fire Manager");
	FireHandler* fireHandler = new FireHandler(20, "FireHandler", fireManager);
	fireManager->attachComponent(fireHandler);
	this->registerObject(fireManager);

	EmptyGameObject* ladderManager = new EmptyGameObject("Ladder Manager");
	LadderHandler* ladderHandler = new LadderHandler(100, "LadderHandler", ladderManager);
	ladderManager->attachComponent(ladderHandler);
	this->registerObject(ladderManager);

	EmptyGameObject* floorManager = new EmptyGameObject("Floor Manager");
	FloorHandler* floorHandler = new FloorHandler(100, "FloorHandler", floorManager);
	floorManager->attachComponent(floorHandler);
	this->registerObject(floorManager);

	EmptyGameObject* hammerManager = new EmptyGameObject("Hammer Manager");
	HammerHandler* hammerHandler = new HammerHandler(100, "HammerHandler", hammerManager);
	ladderManager->attachComponent(hammerHandler);
	this->registerObject(hammerManager);

	UIText* scoreText = new UIText("ScoreText");
	scoreText->setPosition(1920 / 2, 48);
	scoreText->setSize(30);
	scoreText->setText("0");
	this->registerObject(scoreText);
	UIData* scoreData = UIManager::getInstance()->storeData(scoreText->getName());
	scoreData->bindUIText(scoreText);
	scoreData->putInt(UIManager::SCORE_UI_KEY, LevelManager::getInstance()->getScore());
	scoreData->refreshTextFromData(scoreText->getName(), UIManager::SCORE_UI_KEY, "");

	UIText* lifeText = new UIText("LifeText");
	lifeText->setPosition(200, 48);
	lifeText->setSize(30);
	lifeText->setText("LIVES:3");
	this->registerObject(lifeText);
	UIData* lifeData = UIManager::getInstance()->storeData(lifeText->getName());
	lifeData->bindUIText(lifeText);
	lifeData->putInt(UIManager::LIFE_UI_KEY, LevelManager::getInstance()->getLives());
	lifeData->refreshTextFromData(lifeText->getName(), UIManager::LIFE_UI_KEY, "LIVES:");

	UIText* levelText = new UIText("LevelText");
	levelText->setPosition(1700, 48);
	levelText->setSize(30);
	levelText->setText("LEVEL:");
	this->registerObject(levelText);
	UIData* levelData = UIManager::getInstance()->storeData(levelText->getName());
	levelData->bindUIText(levelText);
	levelData->putInt(UIManager::LEVEL_UI_KEY, LevelManager::getInstance()->getLevel());
	levelData->refreshTextFromData(levelText->getName(), UIManager::LEVEL_UI_KEY, "LEVEL:");

	GameScreen* ui = new GameScreen("GameScreen");
	this->registerObject(ui);

	Border* lowerBorder = new Border("Border");
	lowerBorder->setPosition(1920 / 2, 2000);
	this->registerObject(lowerBorder);

	Border* dkBorder = new Border("Border");
	dkBorder->setPosition(490, 220);
	dkBorder->getTransformable()->setScale(0.08f, 2.2f);
	this->registerObject(dkBorder);

	Border* paulineBorder = new Border("Pauline");
	paulineBorder->setPosition(1200, 50);
	paulineBorder->getTransformable()->setScale(0.04f, 2.2f);
	this->registerObject(paulineBorder);

	BGObject* pauline = new BGObject("Pauline");
	pauline->setPosition(1200, 60);
	this->registerObject(pauline);

	Player* player = new Player("Player");
	this->registerObject(player);
	player->getTransformable()->setPosition(630, 950);
	player->setSpawnPosition(630, 950);

	DonkeyKong* dk = new DonkeyKong("DonkeyKong");
	this->registerObject(dk);
	dk->getTransformable()->setPosition(630, 215);

	SFXManager::getInstance()->stopPlaying("results");
	SFXManager::getInstance()->playSound("background");
}

void Level3Scene::onUnloadResources()
{
	TextureManager::getInstance()->unloadAll();
}