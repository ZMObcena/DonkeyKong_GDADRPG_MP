#include "Player.h"

Player::Player(std::string name) : AGameObject(name)
{
	this->name = name;
}

Player::~Player()
{

}

void Player::initialize()
{
	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*TextureManager::getInstance()->getTexture("Eagle"));
	sf::Vector2u textureSize = sprite->getTexture()->getSize();
	this->sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);
	this->transformable.setPosition(640 / 2, 480 / 2);
	//this->transformable.setPosition(400, 100);

	PlayerInputController* input = new PlayerInputController(this->name + " Input");
	this->attachComponent(input);

	PlayerMovement* movement = new PlayerMovement(this->name + " Controls");
	this->attachComponent(movement);

	Renderer* renderer = new Renderer(this->name + " Renderer");
	renderer->assignDrawable(sprite);
	this->attachComponent(renderer);
}

sf::Transformable* Player::getTransformable()
{
	return &this->transformable;
}

float Player::getSpeed()
{
	return this->fPlayerSpeed;
}