#pragma once
#include "AComponent.h"

class FireMovement : public AComponent
{
public:
	FireMovement(std::string name);
	void perform();

private:
	float velocityY = 0.0f;
	const float gravity = 100.0f; // Gravity acceleration
};

