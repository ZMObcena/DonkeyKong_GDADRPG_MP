#pragma once

#include "SFML/Graphics.hpp"

class FloorManager
{
public:
	static FloorManager* getInstance();
	void setDestination(float x, float y);
	sf::Vector2f getDestination();

private:
	FloorManager() {};
	FloorManager(FloorManager const&) {};
	FloorManager& operator=(FloorManager const&) {};

	static FloorManager* sharedInstance;

	sf::Vector2f destination;
};

