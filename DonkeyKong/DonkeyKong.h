#pragma once

#include "AGameObject.h"
#include "Renderer.h"
#include "TextureManager.h"
#include <iostream>

class DonkeyKong : public AGameObject
{
public:
	DonkeyKong(std::string name);
	~DonkeyKong();
	void initialize();

};

