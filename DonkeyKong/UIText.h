#pragma once

#include "AGameObject.h"

class UIText : public AGameObject
{
public:
	UIText(std::string name);
	~UIText();
	void initialize();
	void setText(std::string text);
	std::string getText();
	void setSize(unsigned int size);

private:
	sf::Text* text;
};

