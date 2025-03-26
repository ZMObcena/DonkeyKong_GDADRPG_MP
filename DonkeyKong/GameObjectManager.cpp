#include "GameObjectManager.h"
#include <iostream>

AGameObject* GameObjectManager::findObjectByName(std::string name)
{
	if (mGameObjectMap[name] != nullptr)
	{
		return mGameObjectMap[name];
	}
	else
	{
		std::cerr << "Object " << name << " not found" << std::endl;
		return nullptr;
	}
}

std::vector<AGameObject*> GameObjectManager::getAllObject()
{
	return mGameObjectList;
}

int GameObjectManager::activeObject()
{
	return mGameObjectList.size();
}

void GameObjectManager::processInput(sf::Event event)
{
	for (int i = 0; i < mGameObjectList.size(); i++)
	{
		mGameObjectList[i]->processInput(event);
	}
}

void GameObjectManager::update(sf::Time time)
{
	for (int i = 0; i < mGameObjectList.size(); i++)
	{
		mGameObjectList[i]->update(time);
	}
}

void GameObjectManager::draw(sf::RenderWindow* window)
{
	for (int i = 0; i < mGameObjectList.size(); i++)
	{
		mGameObjectList[i]->draw(window, sf::RenderStates::Default);
	}
}

void GameObjectManager::addObject(AGameObject* gameObject)
{
	mGameObjectMap[gameObject->getName()] = gameObject;
	mGameObjectList.push_back(gameObject);
	gameObject->initialize();
}

void GameObjectManager::deleteObject(AGameObject* gameObject)
{
	std::string key = gameObject->getName();
	delete gameObject;
	mGameObjectMap.erase(key);
	mGameObjectList.erase(std::remove(mGameObjectList.begin(), mGameObjectList.end(), gameObject));
	mGameObjectList.shrink_to_fit();
}

void GameObjectManager::deleteObjectByName(std::string name)
{
	AGameObject* gameObject = findObjectByName(name);

	if (gameObject != nullptr)
	{ 
		deleteObject(gameObject);
	}
}

void GameObjectManager::deleteAllObjectsInScene()
{
	for (int i = 0; i < this->mGameObjectList.size(); i++)
	{
		delete this->mGameObjectList[i];
	}

	this->mGameObjectList.clear();
	this->mGameObjectList.shrink_to_fit();
	this->mGameObjectList.clear();
}

GameObjectManager* GameObjectManager::sharedInstance = nullptr;

GameObjectManager* GameObjectManager::getInstance()
{
	if (sharedInstance == nullptr)
	{
		sharedInstance = new GameObjectManager();
	}
	return sharedInstance;
};