#include "DonkeyKong.h"
#include "DonkeyKongMovement.h"

DonkeyKong::DonkeyKong(std::string name) : AGameObject(name)
{
	this->name = name;
}

DonkeyKong::~DonkeyKong()
{

}

void DonkeyKong::initialize()
{
	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*TextureManager::getInstance()->getTexture("DonkeyKong"));
	sf::Vector2u textureSize = sprite->getTexture()->getSize();
	sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);
	sprite->setTextureRect(TextureManager::getInstance()->getSpriteRect("DonkeyKong", 0));
	sprite->setScale(2.0f, 2.0f);
	sf::FloatRect bounds = sprite->getLocalBounds();
	sprite->setOrigin(bounds.width / 2, bounds.height / 2);

	DonkeyKongMovement* movement = new DonkeyKongMovement(this->name + " Controls");
	this->attachComponent(movement);

	Renderer* renderer = new Renderer(this->name + " Renderer");
	renderer->assignDrawable(sprite);
	this->attachComponent(renderer);
}
