#include "ResultsScreen.h"
#include "TextureManager.h"
#include "GameObjectManager.h"
#include "ApplicationManager.h"
#include "SceneManager.h"
#include "Renderer.h"
#include <iostream>
#include <string>
#include "UIButton.h"
#include "UIText.h"
#include "LevelManager.h"

ResultsScreen::ResultsScreen(std::string name) : AGameObject(name), ButtonListener()
{
	this->startButton = NULL;
	this->exitButton = NULL;
}

void ResultsScreen::initialize()
{
	sf::Texture* normal = TextureManager::getInstance()->getTexture("Start_normal");
	sf::Texture* pressed = TextureManager::getInstance()->getTexture("Start_pressed");

	this->startButton = new UIButton("StartButton", normal, pressed);
	this->attachChild(this->startButton);
	this->startButton->setPosition(1920 / 2 - 180, 880);
	this->startButton->getTransformable()->setScale(1.5f, 1.5f);
	this->startButton->setButtonListener(this);
	//this->startButton->getSprite()->setScale(4.0f, 4.0);

	normal = TextureManager::getInstance()->getTexture("Exit_normal");
	pressed = TextureManager::getInstance()->getTexture("Exit_pressed");

	this->exitButton = new UIButton("ExitButton", normal, pressed);
	this->attachChild(this->exitButton);
	this->exitButton->setPosition(1920 / 2 + 180, 880);
	this->exitButton->getTransformable()->setScale(1.5f, 1.5f);
	this->exitButton->setButtonListener(this);
	//this->startButton->getSprite()->setScale(4.0f, 4.0);

	normal = TextureManager::getInstance()->getTexture("Title");
	pressed = TextureManager::getInstance()->getTexture("Title");
	int level = LevelManager::getInstance()->getLevel();
	int lives = LevelManager::getInstance()->getLives();

	if (level > 3)
	{
		UIText* prompt = new UIText("Prompt");
		this->attachChild(prompt);
		prompt->setPosition(1920 / 2, 700);
		prompt->setSize(80);
		prompt->setText("YOU WIN!");
	}
	if (level < 3 && lives > 0)
	{
		UIText* prompt = new UIText("Prompt");
		this->attachChild(prompt);
		prompt->setPosition(1920 / 2, 700);
		prompt->setSize(80);
		prompt->setText("CONTINUE?");
	}

	if (lives < 0)
	{
		UIText* prompt = new UIText("Prompt");
		this->attachChild(prompt);
		prompt->setPosition(1920 / 2, 700);
		prompt->setSize(80);
		prompt->setText("GAME OVER");
	}

}

void ResultsScreen::onButtonClick(UIButton* button)
{
	std::cout << button->getName();
}

void ResultsScreen::onButtonReleased(UIButton* button)
{
	if (button == this->exitButton)
	{
		ApplicationManager::getInstance()->applicationQuit();
	}

	if (button == this->startButton)
	{
		int level = LevelManager::getInstance()->getLevel();
		int lives = LevelManager::getInstance()->getLives();

		if (level == 1 || level > 3)
		{
			LevelManager::getInstance()->proceedToNextLevel(true);
			SceneManager::getInstance()->loadScene(SceneManager::LEVEL_1_SCENE);
			if (lives < 0 || level > 3)
			{
				LevelManager::getInstance()->reset();
			}
		}
		else if (level == 2)
		{
			LevelManager::getInstance()->proceedToNextLevel(true);
			SceneManager::getInstance()->loadScene(SceneManager::LEVEL_2_SCENE);
			if (lives < 0)
			{
				LevelManager::getInstance()->reset();
			}
		}
		else if (level == 3)
		{
			LevelManager::getInstance()->proceedToNextLevel(true);
			SceneManager::getInstance()->loadScene(SceneManager::LEVEL_3_SCENE);
			if (lives < 0)
			{
				LevelManager::getInstance()->reset();
			}
		}
	}
}
