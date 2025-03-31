#pragma once

#include "AGameObject.h"
#include "PlayerInputController.h"
#include "PlayerMovement.h"
#include "Renderer.h"
#include "TextureManager.h"
#include <iostream>

#include "CollisionListener.h"
#include "Collider.h"

class Player : public AGameObject, public CollisionListener
{
public:
	Player(std::string name);
	~Player();
	void initialize();

	float getSpeed();
	void onCollisionEnter(AGameObject* object);
	void onCollisionExit(AGameObject* object);
	
	bool isOnFloor();
	bool isOnLadder();
	bool isUsingHammer();
	void setUsingHammer(bool hammer);
	void setSpawnPosition(float x, float y);
	bool facingRight = false;

private:
	void lifeCheck(int life);


private:
	float fPlayerSpeed = 250.f;
	bool onFloor = false;
	bool onLadder = false;
	bool isHammer = false;

	int lives;
	int score;

	sf::Vector2f spawn;
};

