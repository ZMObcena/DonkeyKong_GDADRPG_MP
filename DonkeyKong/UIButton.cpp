#include "UIButton.h"
#include "TextureManager.h"
#include "Renderer.h"
#include <iostream>
#include "UIButtonInputController.h"

UIButton::UIButton(std::string name, sf::Texture* normal, sf::Texture* pressed) : AGameObject(name)
{
	this->normal = normal;
	this->pressed = pressed;
}

void UIButton::initialize()
{
	sprite = new sf::Sprite();
	sprite->setTexture(*this->normal);
	sf::Vector2u textureSize = sprite->getTexture()->getSize();
	sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);

	Renderer* renderer = new Renderer(this->name + " Renderer");
	renderer->assignDrawable(sprite);
	this->attachComponent(renderer);
}

void UIButton::changeButtonToNormal()
{
	this->sprite->setTexture(*this->normal);
}

void UIButton::changeButtonToPressed()
{
	this->sprite->setTexture(*this->pressed);
}

sf::FloatRect UIButton::getLocalBounds()
{
	return this->sprite->getLocalBounds();
}

sf::FloatRect UIButton::getGlobalBounds()
{
	sf::FloatRect bounds = this->sprite->getGlobalBounds();
	
	AGameObject* parentObj = this;
	std::vector<AGameObject*> parentList;
	while (parentObj != nullptr)
	{
		parentList.push_back(parentObj);
		parentObj = parentObj->getParent();
	}

	sf::Transform transform = sf::Transform::Identity;
	int startIdx = parentList.size() - 1;
	for (int i = startIdx; i >= 0; i--)
	{
		transform = transform * parentList[i]->getTransformable()->getTransform();
	}
	
	bounds = transform.transformRect(bounds);

	return bounds;
}

void UIButton::setButtonListener(ButtonListener* listener)
{
	this->listener = listener;
	UIButtonInputController* inputController = new UIButtonInputController("UI_InputController", this->listener);
	this->attachComponent(inputController);
}
