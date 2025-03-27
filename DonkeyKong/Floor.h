#pragma once

#include "CollisionListener.h"
#include "Collider.h"
#include "AGameObject.h"
#include "TextureManager.h"

class Floor : public AGameObject, public CollisionListener
{
public:
	Floor(std::string name);
	~Floor();
	void initialize();

	void onCollisionEnter(AGameObject* object);
	void onCollisionExit(AGameObject* object);

private:

protected:
	sf::Transformable transformable;
	std::string name;
	sf::Sprite* sprite;
	sf::Texture* texture;
};

