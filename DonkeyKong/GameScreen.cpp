#include "GameScreen.h"
#include "TextureManager.h"
#include "FontManager.h"
#include "UIData.h"
#include "UIManager.h"
#include "LevelManager.h"

GameScreen::GameScreen(std::string name) : AGameObject(name)
{

}

void GameScreen::initialize()
{
	sf::Texture* normal = TextureManager::getInstance()->getTexture("BarrelBG");
	sf::Texture *pressed = TextureManager::getInstance()->getTexture("BarrelBG");

	UIButton* barrel1 = new UIButton("BarrelBG_1", normal, pressed);
	this->attachChild(barrel1);
	barrel1->setPosition(535, 230);
	barrel1->getTransformable()->setScale(2.2f, 2.2f);

	UIButton* barrel2 = new UIButton("BarrelBG_2", normal, pressed);
	this->attachChild(barrel2);
	barrel2->setPosition(490, 230);
	barrel2->getTransformable()->setScale(2.2f, 2.2f);

	UIButton* barrel3 = new UIButton("BarrelBG_3", normal, pressed);
	this->attachChild(barrel3);
	barrel3->setPosition(445, 230);
	barrel3->getTransformable()->setScale(2.2f, 2.2f);
}

void GameScreen::onButtonClick(UIButton* button)
{

}

void GameScreen::onButtonReleased(UIButton* button)
{

}
