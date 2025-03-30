#include "Player.h"
#include "PhysicsManager.h"
#include "SceneManager.h"
#include "ObjectPoolHolder.h"
#include "GameObjectPool.h"
#include "LevelManager.h"

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
	sf::FloatRect bounds = sprite->getLocalBounds();
	sprite->setOrigin(bounds.width / 2, bounds.height / 2);

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

	if (object->getName() == "Barrel")
	{
		if (!isUsingHammer())
		{
			this->lives--;
			this->lifeCheck(this->lives);
		}
		else
		{
			this->score += 100;
		}
	}	

	if (object->getName() == "Fire")
	{
		if (!isUsingHammer())
		{
			this->lives--;
			this->lifeCheck(this->lives);
		}
		else
		{
			this->score += 300;
		}
	}
	
	if (object->getName() == "Hammer")
	{
		this->isHammer = true;
	}

	if (object->getName() == "Border")
	{
		this->lives--;
		this->lifeCheck(this->lives);
	}

	if (object->getName() == "Pauline")
	{
		LevelManager::getInstance()->setLevel(LevelManager::getInstance()->getLevel() + 1);

	}

	std::cout << "Player entered " + object->getName() << std::endl;

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

	std::cout << "Player exited " + object->getName() << std::endl;
}

void Player::setSpawnPosition(float x, float y)
{
	this->spawn.x = x;
	this->spawn.y = y;
}

void Player::lifeCheck(int life)
{
	if (life < 0)
	{
		//ObjectPoolHolder::getInstance()->unregisterObjectPool(GameObjectManager::getInstance()->findObjectByName(ObjectPoolHolder::BARREL_POOL_TAG));
		SceneManager::getInstance()->loadScene(SceneManager::MAIN_MENU_SCENE);
	}
	else
	{
		this->setPosition(this->spawn.x, this->spawn.y);
	}
}

bool Player::isOnFloor() { return this->onFloor; }

bool Player::isOnLadder() { return this->onLadder; }

bool Player::isUsingHammer() { return this->isHammer; }

void Player::setUsingHammer(bool hammer) { this->isHammer = hammer; }

float Player::getSpeed() { return this->fPlayerSpeed; }