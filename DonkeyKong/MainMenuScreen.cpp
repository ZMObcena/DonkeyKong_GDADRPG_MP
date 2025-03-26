#include "MainMenuScreen.h"
#include "TextureManager.h"
#include "Renderer.h"
#include "GameObjectManager.h"
#include <iostream>
#include <string>
#include "UIButton.h"

MainMenuScreen::MainMenuScreen(std::string name) : AGameObject(name), ButtonListener()
{

}

void MainMenuScreen::initialize()
{
	sf::Texture* normal = TextureManager::getInstance()->getTexture("btn_normal");
	sf::Texture* pressed = TextureManager::getInstance()->getTexture("btn_pressed");

	UIButton* startButton = new UIButton("StartButton", normal, pressed);
	this->attachChild(startButton);
	startButton->setPosition(2,2);
	startButton->getSprite()->setScale(1.0f, 1.0);
}

void MainMenuScreen::onButtonClick(UIButton* button)
{

}

void MainMenuScreen::onButtonReleased(UIButton* button)
{

}
