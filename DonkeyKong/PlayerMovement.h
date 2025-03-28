#pragma once
#include "AComponent.h"
#include "Player.h"
#include "PlayerInputController.h"
#include "GameObjectManager.h"

class PlayerMovement : public AComponent
{
public:
	PlayerMovement(std::string name);
	void perform();

private:
	bool isJumping = false;
	float velocityY = 0.0f;
	float jumpDirection = 0.0f;
	const float gravity = 980.0f; // Gravity acceleration
	const float jumpStrength = -350.0f; // Upward force when jumping
};

