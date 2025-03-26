#pragma once
#include "AGameObject.h"
#include <unordered_map>
#include <vector>

class GameObjectManager
{
public:
	static GameObjectManager* getInstance();
	AGameObject* findObjectByName(std::string name);
	std::vector<AGameObject*> getAllObject();

	int activeObject();
	void processInput(sf::Event event);
	void update(sf::Time time);
	void draw(sf::RenderWindow* window);

	void addObject(AGameObject* gameObject);
	void deleteObject(AGameObject* gameObject);
	void deleteObjectByName(std::string name);
	void deleteAllObjectsInScene();

private:
	GameObjectManager() {};
	GameObjectManager(GameObjectManager const&) {};
	GameObjectManager& operator=(GameObjectManager const&) {};

	static GameObjectManager* sharedInstance;

	std::unordered_map<std::string, AGameObject*> mGameObjectMap;
	std::vector<AGameObject*> mGameObjectList;
};

