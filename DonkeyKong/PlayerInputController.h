#pragma once
#include "GenericInputController.h"

class PlayerInputController : public GenericInputController
{
public:
	PlayerInputController(std::string name);
	~PlayerInputController();

	void perform();
	bool isUp();
	bool isDown();
	bool isRight();
	bool isLeft();

private:
	void processKeyInput(bool pressed);

private:
	const float SPEED_MULTIPLIER = 300.0f;
	bool moveUp = false;
	bool moveDown = false;
	bool moveRight = false;
	bool moveLeft = false;
};

