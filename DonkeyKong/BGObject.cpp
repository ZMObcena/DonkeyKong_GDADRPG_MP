#include "BGObject.h"

BGObject::BGObject(std::string name) : AGameObject(name)
{
	this->name = name;
}

BGObject::~BGObject() {}

void BGObject::initialize()
{
	sprite = new sf::Sprite();
	sprite->setTexture(*TextureManager::getInstance()->getTexture("desert_bg"));
	sf::Vector2u textureSize = this->sprite->getTexture()->getSize();
	sprite->setTextureRect(sf::IntRect(0, 0, 1000, 1000 * 8));
	sprite->setPosition(0, -1000 * 7);

	Renderer* renderer = new Renderer("BGObjectSprite");
	renderer->assignDrawable(sprite);
	this->attachComponent(renderer);
}
