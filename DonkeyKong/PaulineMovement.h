#pragma once

#include "AComponent.h"
class PaulineMovement : public AComponent
{
public:
	PaulineMovement(std::string name);
	void perform();
};

