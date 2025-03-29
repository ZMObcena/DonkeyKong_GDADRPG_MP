#pragma once
#include "AComponent.h"
#include "Barrel.h"

class BarrelMovement : public AComponent
{
public:
	BarrelMovement(std::string name);
	void perform();

private:
	bool hasFallen = false;
	int direction = 1;
	float velocityY = 0.0f;
	const float gravity = 100.0f; // Gravity acceleration

	int frameIndex = 1;
	float animationTimer = 0.0f;
	float animationSpeed = 0.1f;
};

