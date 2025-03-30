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

	UIText* livesText = new UIText("Lives Text");
	this->attachChild(livesText);
	livesText->setFont("Dejavu");
	livesText->setPosition(150, 100);

	UIText* scoreText = new UIText("ScoreText");
	this->attachChild(scoreText);

	//UIData* scoreData = UIManager::getInstance()->storeData(score->getName());
	//scoreData->bindUIText(scoreText);
	//scoreData->putInt(UIManager::SCORE_UI_KEY, 0);
	//scoreData->refreshTextFromData(scoreText->getName(), UIManager::SCORE_UI_KEY, "SCORE: ");

	//livesText->setText("Lives: " << );
}

void GameScreen::onButtonClick(UIButton* button)
{

}

void GameScreen::onButtonReleased(UIButton* button)
{

}
