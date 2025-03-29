#include "GameScreen.h"
#include "TextureManager.h"

GameScreen::GameScreen(std::string name) : AGameObject(name)
{

}

void GameScreen::initialize()
{
	sf::Texture* normal = TextureManager::getInstance()->getTexture("Lives");
	sf::Texture* pressed = TextureManager::getInstance()->getTexture("Lives");

	int offset = 390;
	UIButton* lives = new UIButton("Life 1", normal, pressed);
	this->attachChild(lives);
	lives->setPosition(70 + offset, 100);
	lives->getTransformable()->setScale(-2.f, 2.f);

	lives = new UIButton("Life 2", normal, pressed);
	this->attachChild(lives);
	lives->setPosition(110 + offset, 100);
	lives->getTransformable()->setScale(-2.f, 2.f);

	lives = new UIButton("Life 3", normal, pressed);
	this->attachChild(lives);
	lives->setPosition(150 + offset, 100);
	lives->getTransformable()->setScale(-2.f, 2.f);

	UIText* livesText = new UIText("Lives Text");
	this->attachChild(livesText);
	livesText->setFont("Sansation");
	livesText->setText("Lives: ");
	livesText->setPosition(150 + offset, 100);
}

void GameScreen::onButtonClick(UIButton* button)
{

}

void GameScreen::onButtonReleased(UIButton* button)
{

}
