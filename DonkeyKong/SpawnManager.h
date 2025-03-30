#pragma once

#include "SFML/Graphics.hpp"

class SpawnManager
{
public:
	static SpawnManager* getInstance();

	void setLadderSpawn(float x, float y);
	void setFloorSpawn(float x, float y);
	void setFloorSpawn(float x, float y, float scaleX, float scaleY);
	void setBarrelSpawn(float x, float y);
	void setFireSpawn(float x, float y);
	void setDKSpawn(float x, float y);
	void setPlayerSpawn(float x, float y);
	void setHammerSpawn(float x, float y);

	sf::Vector2f getLadderSpawn();
	sf::Vector2f getFloorSpawn();
	sf::Vector2f getScale();
	sf::Vector2f getBarrelSpawn();
	sf::Vector2f getFireSpawn();
	sf::Vector2f getDKSpawn();
	sf::Vector2f getPlayerSpawn();
	sf::Vector2f getHammerSpawn();

private:
	SpawnManager() {};
	SpawnManager(SpawnManager const&) {};
	SpawnManager& operator=(SpawnManager const&) {};

	static SpawnManager* sharedInstance;
	
	sf::Vector2f scale;

	sf::Vector2f ladderSpawn;
	sf::Vector2f floorSpawn;
	sf::Vector2f barrelSpawn;
	sf::Vector2f fireSpawn;
	sf::Vector2f dkSpawn;
	sf::Vector2f playerSpawn;
	sf::Vector2f hammerSpawn;
};

