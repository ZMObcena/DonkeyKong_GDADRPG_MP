#include "AGameObject.h"

AGameObject::AGameObject(std::string name)
{
	this->name = name;
}

AGameObject::~AGameObject()
{
	if (this->sprite != NULL)
	{
		delete this->sprite;
	}
}

std::string AGameObject::getName()
{
	return this->name;
}

sf::Sprite* AGameObject::getSprite()
{
	return sprite;
}

sf::Transformable* AGameObject::getTransformable()
{
	return &this->transformable;
}

void AGameObject::processInput(sf::Event event)
{
	if (!this->isEnabled()) return;

	std::vector<AComponent*> componentList = this->getComponentsOfType(AComponent::ComponentType::Input);
	for (int j = 0; j < componentList.size(); j++)
	{
		((GenericInputController*)componentList[j])->assignEvent(event);
		componentList[j]->perform();
	}

	for (int i = 0; i < this->childList.size(); i++)
	{
		childList[i]->processInput(event);
	}
}

void AGameObject::draw(sf::RenderWindow* targetWindow, sf::RenderStates renderStates)
{
	if (!this->isEnabled()) return;

	renderStates.transform = renderStates.transform * this->transformable.getTransform();

	std::vector<AComponent*> componentList = this->getComponentsOfType(AComponent::ComponentType::Renderer);

	for (int j = 0; j < componentList.size(); j++)
	{
		Renderer* renderer = (Renderer*)componentList[j];
		renderer->assignTargetWindow(targetWindow);
		renderer->setRenderStates(renderStates);
		renderer->perform();
	}

	for (int i = 0; i < this->childList.size(); i++)
	{
		AGameObject* child = this->childList[i];
		child->draw(targetWindow, renderStates);
	}
}

void AGameObject::update(sf::Time time)
{
	if (!this->isEnabled()) return;

	std::vector<AComponent*> componentList = this->getComponentsOfType(AComponent::ComponentType::Script);

	for (int j = 0; j < componentList.size(); j++)
	{
		componentList[j]->setDeltaTime(time);
		componentList[j]->perform();
	}

	for (int i = 0; i < this->childList.size(); i++)
	{
		childList[i]->update(time);
	}

}

void AGameObject::attachChild(AGameObject* child)
{
	this->childList.push_back(child);
	child->initialize();
}

void AGameObject::detachChild(AGameObject* child)
{
	int index = -1;
	for (int i = 0; i < this->childList.size(); i++)
	{
		if (this->childList[i] == child)
		{
			index = i;
		}
	}

	if (index != -1)
	{
		this->childList.erase(this->childList.begin() + index);
		this->childList.shrink_to_fit();
	}
}

void AGameObject::attachComponent(AComponent* component)
{
	this->componentList.push_back(component);
	component->attachOwner(this);
}

void AGameObject::detachComponent(AComponent* component)
{
	int index = -1;
	for (int i = 0; i < this->componentList.size(); i++)
	{
		if (this->componentList[i] == component)
		{
			index = i;
			this->componentList[i]->detachOwner();
			break;
		}
	}

	if (index != -1)
	{
		this->componentList.erase(this->componentList.begin() + index);
	}
}

AComponent* AGameObject::findComponentByName(std::string name)
{
	for (int i = 0; i < this->componentList.size(); i++)
	{
		if (this->componentList[i]->getName() == name)
		{
			return this->componentList[i];
		}
	}

	return NULL;
}

AComponent* AGameObject::findComponentByType(AComponent::ComponentType type, std::string name)
{
	for (int i = 0; i < this->componentList.size(); i++)
	{
		if (this->componentList[i]->getName() == name && this->componentList[i]->getType() == type)
		{
			return this->componentList[i];
		}
	}

	return NULL;
}

std::vector<AComponent*> AGameObject::getComponentsOfType(AComponent::ComponentType type)
{
	std::vector<AComponent*> foundList;
	for (int i = 0; i < this->componentList.size(); i++)
	{
		if (this->componentList[i]->getType() == type)
		{
			foundList.push_back(this->componentList[i]);
		}
	}

	return foundList;
}

std::vector<AComponent*> AGameObject::getComponentsOfTypeRecursive(AComponent::ComponentType type)
{
	std::vector<AComponent*> foundList;

	for (int i = 0; i < this->componentList.size(); i++)
	{
		if (this->componentList[i]->getType() == type)
		{
			foundList.push_back(this->componentList[i]);
		}
	}

	for (int i = 0; i < this->childList.size(); i++)
	{
		foundList = this->getComponentsRecursiveProper(this->childList[i], type, foundList);
	}

	return foundList;
}

void AGameObject::setPosition(float x, float y)
{
	this->transformable.setPosition(x, y);
}

std::vector<AComponent*> AGameObject::getComponentsRecursiveProper(AGameObject* object, AComponent::ComponentType type, std::vector<AComponent*> foundList)
{
	std::vector<AComponent*> components = object->getComponentsOfType(type);

	foundList.insert(foundList.end(), components.begin(), components.end());

	for (int i = 0; i < object->childList.size(); i++)
	{
		foundList = getComponentsRecursiveProper(object->childList[i], type, foundList);
	}

	return foundList;
}


void AGameObject::setEnabled(bool flag)
{
	this->enabled = flag;
}

bool AGameObject::isEnabled() { return this->enabled; }

sf::Transform AGameObject::getGlobalTransform()
{
	AGameObject* parentObj = this;
	std::vector<AGameObject*> parentList;
	while (parentObj != NULL)
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

	return transform;
}