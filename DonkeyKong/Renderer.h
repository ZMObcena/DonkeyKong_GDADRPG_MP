#pragma once
#include "AComponent.h"

class Renderer : public AComponent
{
public:
	Renderer(std::string name);
	~Renderer();
	void assignTargetWindow(sf::RenderWindow* window);
	void assignDrawable(sf::Drawable* drawable);
	void setRenderStates(sf::RenderStates renderStates);

	void perform();

	static Renderer* CreateSprite(std::string name, std::string resourceName);

private:
	sf::RenderWindow* targetWindow;
	sf::Drawable* drawable;
	sf::RenderStates renderStates;
};

