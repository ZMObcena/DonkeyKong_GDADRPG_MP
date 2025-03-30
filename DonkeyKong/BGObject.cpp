#include "BGObject.h"
#include "PaulineMovement.h"

BGObject::BGObject(std::string name) : AGameObject(name)
{
	this->name = name;
}

BGObject::~BGObject() {}

void BGObject::initialize()
{
	sprite = new sf::Sprite();
	sprite->setTexture(*TextureManager::getInstance()->getTexture("Pauline"));
	sf::Vector2u textureSize = this->sprite->getTexture()->getSize();
	this->sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);
	this->sprite->setScale(2.0f, 2.0f);
	int totalFrames = 5; // Number of frames in the sprite sheet
	int frameWidth = textureSize.x / totalFrames;
	int frameHeight = textureSize.y;

	sprite->setTextureRect(sf::IntRect(0, 0, frameWidth, frameHeight));
	this->sprite->setOrigin(frameWidth / 2, frameHeight / 2);

	PaulineMovement* script = new PaulineMovement(this->name + " Movement");
	this->attachComponent(script);

	Renderer* renderer = new Renderer(this->name + " Renderer");
	renderer->assignDrawable(sprite);
	this->attachComponent(renderer);
}
