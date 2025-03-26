#pragma once
#include "AGameObject.h"
#include "PlayerInputController.h"
#include "PlayerMovement.h"
#include "Renderer.h"
#include "TextureManager.h"
#include <iostream>

class Player : public AGameObject
{
public:
	Player(std::string name);
	~Player();
	void initialize();

	sf::Transformable* getTransformable();
	float getSpeed();

private:
	bool bIsMovingUp = false;
	bool bIsMovingDown = false;
	bool bIsMovingLeft = false;
	bool bIsMovingRight = false;

	float fPlayerSpeed = 500.f;

protected:
	sf::Transformable transformable;
	std::string name;
	sf::Sprite* sprite;
	sf::Texture* texture;
};

