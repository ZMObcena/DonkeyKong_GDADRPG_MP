#include "GameScreen.h"
#include "TextureManager.h"
//#include
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

	normal = TextureManager::getInstance()->getTexture("BarrelBG");
	pressed = TextureManager::getInstance()->getTexture("BarrelBG");

	UIButton* barrel = new UIButton("BarrelBG_1", normal, pressed);
	this->attachChild(barrel);
	barrel->setPosition(535, 230);
	barrel->getTransformable()->setScale(2.2f, 2.2f);

	barrel = new UIButton("BarrelBG_2", normal, pressed);
	this->attachChild(barrel);
	barrel->setPosition(490, 230);
	barrel->getTransformable()->setScale(2.2f, 2.2f);

	barrel = new UIButton("BarrelBG_3", normal, pressed);
	this->attachChild(barrel);
	barrel->setPosition(445, 230);
	barrel->getTransformable()->setScale(2.2f, 2.2f);

	UIText* livesText = new UIText("Lives Text");
	this->attachChild(livesText);
	livesText->setFont("Sansation");
	//livesText->setText("Lives: " << );
	livesText->setPosition(150 + offset, 100);
}

void GameScreen::onButtonClick(UIButton* button)
{

}

void GameScreen::onButtonReleased(UIButton* button)
{

}
