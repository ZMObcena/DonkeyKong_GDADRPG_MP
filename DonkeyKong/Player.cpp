#include "Player.h"
#include "PhysicsManager.h"

Player::Player(std::string name) : AGameObject(name), CollisionListener()
{
	this->name = name;
}

Player::~Player()
{

}

void Player::initialize()
{
	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*TextureManager::getInstance()->getTexture("Mario"));
	sf::Vector2u textureSize = sprite->getTexture()->getSize();
	sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);
	sprite->setTextureRect(TextureManager::getInstance()->getSpriteRect("Mario", 7));
	sprite->setScale(3.0f, 3.0f);

	PlayerInputController* input = new PlayerInputController(this->name + " Input");
	this->attachComponent(input);

	PlayerMovement* movement = new PlayerMovement(this->name + " Controls");
	this->attachComponent(movement);

	Renderer* renderer = new Renderer(this->name + " Renderer");
	renderer->assignDrawable(sprite);
	this->attachComponent(renderer);

	Collider* collider = new Collider(this->name + " Collider");
	collider->setOffset(sprite->getGlobalBounds());
	collider->assignListener(this);
	this->attachComponent(collider);
	PhysicsManager::getInstance()->trackObject(collider);


	//Renderer* renderer = Renderer::CreateSprite("Player", "Mario");
	//this->attachComponent(renderer);
}

void Player::onCollisionEnter(AGameObject* object)
{
	if (object->getName() == "Floor")
	{
		this->onFloor = true;
	}

	if (object->getName() == "Ladder")
	{
		this->onLadder = true;
	}

	std::cout << "Player entered " + object->getName();

}

void Player::onCollisionExit(AGameObject* object)
{
	if (object->getName() == "Floor")
	{
		this->onFloor = false;
	}

	if (object->getName() == "Ladder")
	{
		this->onLadder = false;
	}
	std::cout << "Player exited " + object->getName();
}

bool Player::isOnFloor() { return this->onFloor; }

bool Player::isOnLadder() { return this->onLadder; }

float Player::getSpeed()
{
	return this->fPlayerSpeed;
}