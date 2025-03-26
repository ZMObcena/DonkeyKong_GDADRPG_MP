#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "AComponent.h"
#include "GenericInputController.h"
#include "Renderer.h"

class AGameObject
{
public:
	AGameObject(std::string name);
	virtual ~AGameObject();
	virtual void initialize() = 0;
	void processInput(sf::Event event);
	void update(sf::Time deltaTime);
	void draw(sf::RenderWindow* targetWindow, sf::RenderStates renderStates);

	sf::Transformable* getTransformable();
	std::string getName();
	sf::Sprite* getSprite();

	void attachChild(AGameObject* child);
	void detachChild(AGameObject* child);
	void attachComponent(AComponent* component);
	void detachComponent(AComponent* component);
	AComponent* findComponentByName(std::string name);
	AComponent* findComponentByType(AComponent::ComponentType type, std::string name);
	std::vector<AComponent*> getComponentsOfType(AComponent::ComponentType type);
	std::vector<AComponent*> getComponentsOfTypeRecursive(AComponent::ComponentType type);

	void setPosition(float x, float y);
	void setEnabled(bool flag);
	bool isEnabled();

	sf::Transform getGlobalTransform();

	AGameObject* getParent();


protected:
	void setParent(AGameObject* object);

	sf::Transformable transformable;
	std::string name;
	sf::Sprite* sprite;
	sf::Texture* texture;
	std::vector<AGameObject*> childList;
	std::vector<AComponent*> componentList;

private:
	AGameObject* parent;
	std::vector<AComponent*> getComponentsRecursiveProper(AGameObject* object, AComponent::ComponentType type, std::vector<AComponent*> foundList);
	bool enabled = true;
};

