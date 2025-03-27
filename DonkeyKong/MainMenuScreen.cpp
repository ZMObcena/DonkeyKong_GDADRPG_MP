#include "MainMenuScreen.h"
#include "TextureManager.h"
#include "GameObjectManager.h"
#include "ApplicationManager.h"
#include "SceneManager.h"
#include "Renderer.h"
#include <iostream>
#include <string>
#include "UIButton.h"

MainMenuScreen::MainMenuScreen(std::string name) : AGameObject(name), ButtonListener()
{
	this->startButton = NULL;
	this->exitButton = NULL;
}

void MainMenuScreen::initialize()
{
	sf::Texture* normal = TextureManager::getInstance()->getTexture("Start_normal");
	sf::Texture* pressed = TextureManager::getInstance()->getTexture("Start_pressed");

	this->startButton = new UIButton("StartButton", normal, pressed);
	this->attachChild(this->startButton);
	this->startButton->setPosition(1920 / 2, 800);
	this->startButton->getTransformable()->setScale(1.5f, 1.5f);
	this->startButton->setButtonListener(this);
	//this->startButton->getSprite()->setScale(4.0f, 4.0);

	normal = TextureManager::getInstance()->getTexture("Exit_normal");
	pressed = TextureManager::getInstance()->getTexture("Exit_pressed");

	this->exitButton = new UIButton("ExitButton", normal, pressed);
	this->attachChild(this->exitButton);
	this->exitButton->setPosition(1920 / 2, 950);
	this->exitButton->getTransformable()->setScale(1.5f, 1.5f);
	this->exitButton->setButtonListener(this);
	//this->startButton->getSprite()->setScale(4.0f, 4.0);

	normal = TextureManager::getInstance()->getTexture("Title");
	pressed = TextureManager::getInstance()->getTexture("Title");

	this->logo = new UIButton("Logo", normal, pressed);
	this->attachChild(this->logo);
	this->logo->setPosition(1920 / 2, 380);
	this->logo->getTransformable()->setScale(7.0f, 7.0f);

}

void MainMenuScreen::onButtonClick(UIButton* button)
{
	std::cout << button->getName();
}

void MainMenuScreen::onButtonReleased(UIButton* button)
{
	if (button == this->exitButton)
	{
		ApplicationManager::getInstance()->applicationQuit();
	}
	
	if (button == this->startButton)
	{
		SceneManager::getInstance()->loadScene(SceneManager::LEVEL_1_SCENE);
	}
}
