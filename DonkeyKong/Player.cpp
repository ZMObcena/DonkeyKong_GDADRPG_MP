#include "Player.h"
#include "PhysicsManager.h"
#include "SceneManager.h"
#include "ObjectPoolHolder.h"
#include "GameObjectPool.h"
#include "LevelManager.h"
#include "SpawnManager.h"
#include "UIData.h"
#include "UIManager.h"
#include "SFXManager.h"

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

	this->lives = LevelManager::getInstance()->getLives();
	this->score = LevelManager::getInstance()->getScore();
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
			SFXManager::getInstance()->playSound("death");

			this->lives--;
			LevelManager::getInstance()->setLives(this->lives);
			this->lifeCheck(this->lives);
			UIData* lifeData = UIManager::getInstance()->getUIData("LifeText");
			lifeData->putInt(UIManager::LIFE_UI_KEY, lifeData->getInt(UIManager::LIFE_UI_KEY, LevelManager::getInstance()->getLives()) - 1);
			lifeData->refreshTextFromData("LifeText", UIManager::LIFE_UI_KEY, "LIVES:");
		}
		else
		{
			this->score += 100;
			LevelManager::getInstance()->setScore(this->score);
			UIData* scoreData = UIManager::getInstance()->getUIData("ScoreText");
			scoreData->putInt(UIManager::SCORE_UI_KEY, scoreData->getInt(UIManager::SCORE_UI_KEY, LevelManager::getInstance()->getScore()) + 100);
			scoreData->refreshTextFromData("ScoreText", UIManager::SCORE_UI_KEY, "");
		}
	}	

	if (object->getName() == "Fire")
	{
		if (!isUsingHammer())
		{
			SFXManager::getInstance()->playSound("death");

			this->lives--;
			LevelManager::getInstance()->setLives(this->lives);
			this->lifeCheck(this->lives);
			UIData* scoreData = UIManager::getInstance()->getUIData("LifeText");
			scoreData->putInt(UIManager::SCORE_UI_KEY, scoreData->getInt(UIManager::LIFE_UI_KEY, LevelManager::getInstance()->getLives()) - 1);
			scoreData->refreshTextFromData("LifeText", UIManager::LIFE_UI_KEY, "LIVES:");
		}
		else
		{
			this->score += 300;
			LevelManager::getInstance()->setScore(this->score);
			UIData* scoreData = UIManager::getInstance()->getUIData("ScoreText");
			scoreData->putInt(UIManager::LIFE_UI_KEY, scoreData->getInt(UIManager::SCORE_UI_KEY, LevelManager::getInstance()->getScore()) + 300);
			scoreData->refreshTextFromData("ScoreText", UIManager::SCORE_UI_KEY, "");
		}
	}
	
	if (object->getName() == "Hammer")
	{
		this->isHammer = true;
	}

	if (object->getName() == "Border")
	{
		SFXManager::getInstance()->playSound("death");

		this->lives--;
		LevelManager::getInstance()->setLives(this->lives);
		this->isHammer = false;
		this->lifeCheck(this->lives);
		UIData* lifeData = UIManager::getInstance()->getUIData("LifeText");
		lifeData->putInt(UIManager::LIFE_UI_KEY, lifeData->getInt(UIManager::LIFE_UI_KEY, LevelManager::getInstance()->getLives()) - 1);
		lifeData->refreshTextFromData("LifeText", UIManager::LIFE_UI_KEY, "LIVES:");
	}

	if (object->getName() == "Pauline")
	{
		SFXManager::getInstance()->playSound("win1");
		LevelManager::getInstance()->increaseLevel();
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
		SceneManager::getInstance()->loadScene(SceneManager::RESULTS_SCENE);
	}
	else
	{
		this->spawn = SpawnManager::getInstance()->getPlayerSpawn();
		this->setPosition(this->spawn.x, this->spawn.y);
	}
}

bool Player::isOnFloor() { return this->onFloor; }

bool Player::isOnLadder() { return this->onLadder; }

bool Player::isUsingHammer() { return this->isHammer; }

void Player::setUsingHammer(bool hammer) { this->isHammer = hammer; }

float Player::getSpeed() { return this->fPlayerSpeed; }