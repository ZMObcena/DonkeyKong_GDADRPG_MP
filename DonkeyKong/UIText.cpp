#include "UIText.h"
#include "FontManager.h"
#include "Renderer.h"

UIText::UIText(std::string name) : AGameObject(name)
{
	this->text = new sf::Text();
}

UIText::~UIText()
{
	//delete this->text;
}

void UIText::initialize()
{
	sf::Font* font = FontManager::getInstance()->getFont("PressStart");
	this->text->setFont(*font);
	this->text->setFillColor(sf::Color::White);
	this->text->setOutlineColor(sf::Color::Black);
	this->text->setOutlineThickness(8.0f);
	//this->setSize(30);
	this->setText("-");

	Renderer* renderer = new Renderer(this->name + " Renderer");
	renderer->assignDrawable(text);
	this->attachComponent(renderer);
}

void UIText::setText(std::string something)
{
	this->text->setString(something);
	sf::FloatRect bounds = this->text->getLocalBounds();
	this->text->setOrigin(bounds.width / 2, bounds.height / 2);
}

std::string UIText::getText()
{
	return this->text->getString();
}

void UIText::setSize(unsigned int size)
{
	this->text->setCharacterSize(size);
}

void UIText::setFont(std::string font)
{
	sf::Font* fontStyle = FontManager::getInstance()->getFont(font);
	this->text->setFont(*fontStyle);
}
