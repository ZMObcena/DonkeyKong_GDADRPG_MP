#include "GameScreen.h"
#include "TextureManager.h"
#include "FontManager.h"
#include "UIData.h"
#include "UIManager.h"

GameScreen::GameScreen(std::string name) : AGameObject(name)
{

}

void GameScreen::initialize()
{
	sf::Texture* normal = TextureManager::getInstance()->getTexture("BarrelBG");
	sf::Texture *pressed = TextureManager::getInstance()->getTexture("BarrelBG");

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
}

void GameScreen::onButtonClick(UIButton* button)
{

}

void GameScreen::onButtonReleased(UIButton* button)
{

}
