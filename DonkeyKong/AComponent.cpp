#include "AComponent.h"

AComponent::AComponent(std::string name, ComponentType type)
{
	this->name = name;
	this->owner = nullptr;
	this->type = type;
}

AComponent::~AComponent()
{
	this->owner = nullptr;
	this->type = NotSet;
}

void AComponent::attachOwner(AGameObject* owner)
{
	this->owner = owner;
}

void AComponent::detachOwner()
{
	delete this;
}

AGameObject* AComponent::getOwner()
{
	return this->owner;
}

AComponent::ComponentType AComponent::getType()
{
	return this->type;
}

std::string AComponent::getName()
{
	return this->name;
}

void AComponent::setDeltaTime(sf::Time deltaTime)
{
	this->deltaTime = deltaTime;
}
