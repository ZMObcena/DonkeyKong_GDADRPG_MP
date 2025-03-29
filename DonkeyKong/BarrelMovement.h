#pragma once
#include "AComponent.h"
#include "Barrel.h"

class BarrelMovement : public AComponent
{
public:
	BarrelMovement(std::string name);
	void perform();

private:
	float velocityY = 0.0f;
	const float gravity = 100.0f; // Gravity acceleration
};

