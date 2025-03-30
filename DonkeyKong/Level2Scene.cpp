#include "Level2Scene.h"

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
#include "GameScreen.h"
#include "Hammer.h"
#include "Border.h"
#include "Ladder.h"
#include "BGObject.h"
#include "LevelManager.h"

Level2Scene::Level2Scene() : AScene("Level2Scene") {}

void Level2Scene::onLoadResources()
{
	//TextureManager::getInstance()->loadAll();
}

void Level2Scene::onLoadObjects()
{
	srand(time(nullptr));

	EmptyGameObject* holder = new EmptyGameObject("Physics Manager Holder");
	PhysicsManager::initialize("Physics Manager", holder);
	this->registerObject(holder);

	EmptyGameObject* barrelManager = new EmptyGameObject("Barrel Manager");
	BarrelHandler* barrelHandler = new BarrelHandler(150, "BarrelHandler", barrelManager);
	barrelManager->attachComponent(barrelHandler);
	this->registerObject(barrelManager);

	EmptyGameObject* ladderManager = new EmptyGameObject("Ladder Manager");
	LadderHandler* ladderHandler = new LadderHandler(30, "LadderHandler", ladderManager);
	ladderManager->attachComponent(ladderHandler);
	this->registerObject(ladderManager);

	EmptyGameObject* floorManager = new EmptyGameObject("Floor Manager");
	FloorHandler* floorHandler = new FloorHandler(50, "FloorHandler", floorManager);
	floorManager->attachComponent(floorHandler);
	this->registerObject(floorManager);

	EmptyGameObject* hammerManager = new EmptyGameObject("Hammer Manager");
	HammerHandler* hammerHandler = new HammerHandler(6, "HammerHandler", hammerManager);
	ladderManager->attachComponent(hammerHandler);
	this->registerObject(hammerManager);

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
}

void Level2Scene::onUnloadResources()
{
	TextureManager::getInstance()->unloadAll();
}