#pragma once

#include "AComponent.h"
#include "DonkeyKong.h"

class DonkeyKongMovement : public AComponent
{
public:
	DonkeyKongMovement(std::string name);
	void perform();
};

