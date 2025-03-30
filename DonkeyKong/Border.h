#pragma once

#include "AGameObject.h"
#include "Renderer.h"
#include "TextureManager.h"
#include <iostream>

#include "CollisionListener.h"
#include "Collider.h"

class Border : public AGameObject, public CollisionListener
{
public:
	Border(std::string name);
	~Border();
	void initialize();

	void onCollisionEnter(AGameObject* object);
	void onCollisionExit(AGameObject* object);
};

