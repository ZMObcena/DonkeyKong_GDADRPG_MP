#include "MainMenuScreen.h"
#include "TextureManager.h"
#include "Game.h"
#include "Renderer.h"
#include "GameObjectManager.h"
#include <iostream>
#include <string>

MainMenuScreen::MainMenuScreen(std::string name) : AGameObject(name), ButtonListener()
{

}

void MainMenuScreen::initialize()
{
	sf::Texture* normal = TextureManager::getInstance()->getTexture("btn_normal");
	sf::Texture* pressed = TextureManager::getInstance()->getTexture("btn_pressed");

	UIButton* startButton = new UIButton("StartButton", normal, pressed);
	this->attachChild(startButton);
	startButton->setPosition();
	startButton->setScale();

	UIText* startBtnText = new UIText("startText");
	startButton->attachChild(startBtnText);
	startButton->setPosition(10, 10);
	startButton->setSize(50);
	startButton->setText("START");

}

void MainMenuScreen::onButtonClick(UIButton* button)
{

}

void MainMenuScreen::onButtonReleased(UIButton* button)
{

}
