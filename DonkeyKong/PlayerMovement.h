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
	const float SPEED_MULTIPLIER = 300.0f;
};

