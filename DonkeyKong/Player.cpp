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
	this->transformable.setPosition(640 / 2, 480 / 2);

	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*TextureManager::getInstance()->getTexture("Mario"));
	sf::Vector2u textureSize = sprite->getTexture()->getSize();
	sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);
	sprite->setTextureRect(TextureManager::getInstance()->getSpriteRect("Mario", 7));
	sprite->setScale(3.0f, 3.0f);
	sprite->setPosition(200, 200);

	PlayerInputController* input = new PlayerInputController(this->name + " Input");
	this->attachComponent(input);

	PlayerMovement* movement = new PlayerMovement(this->name + " Controls");
	this->attachComponent(movement);

	Renderer* renderer = new Renderer(this->name + " Renderer");
	renderer->assignDrawable(sprite);
	this->attachComponent(renderer);

	//Renderer* renderer = Renderer::CreateSprite("Player", "Mario");
	//this->attachComponent(renderer);
}

float Player::getSpeed()
{
	return this->fPlayerSpeed;
}