#pragma once

#include "AComponent.h"

class DonkeyKongMovement : public AComponent
{
public:
	DonkeyKongMovement(std::string name);
	void perform();
};

