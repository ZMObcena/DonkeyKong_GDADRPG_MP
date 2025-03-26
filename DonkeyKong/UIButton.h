#pragma once

#include "AGameObject.h"
#include "ButtonListener.h"

class UIButton : public AGameObject
{
public:
	UIButton(std::string name, sf::Texture* normal, sf::Texture* pressed);
	void initialize();
	void changeButtonToNormal();
	void changeButtonToPressed();
	sf::FloatRect getLocalBounds();
	sf::FloatRect getGlobalBounds();
	void setButtonListener(ButtonListener* listener);

private:
	sf::Texture* normal;
	sf::Texture* pressed;
	sf::Sprite* sprite;
	ButtonListener* listener;
};

