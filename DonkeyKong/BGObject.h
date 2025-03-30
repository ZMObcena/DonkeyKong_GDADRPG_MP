#pragma once
#include "AGameObject.h"
#include "Game.h"
#include "Renderer.h"
#include <iostream>
#include <vector>

class BGObject : public AGameObject
{
public:
	BGObject(std::string name);
	~BGObject();
	void initialize();

};

