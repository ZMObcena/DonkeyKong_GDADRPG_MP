#include "Renderer.h"
#include "SpriteRenderer.h"

Renderer::Renderer(std::string name) : AComponent(name, AComponent::Renderer)
{
	this->renderStates = sf::RenderStates::Default;
	this->drawable = nullptr;
	this->targetWindow = nullptr;
}

Renderer::~Renderer()
{
	AComponent::~AComponent();
}

void Renderer::assignTargetWindow(sf::RenderWindow* window)
{
	this->targetWindow = window;
}

void Renderer::assignDrawable(sf::Drawable* drawable)
{
	this->drawable = drawable;
}

void Renderer::setRenderStates(sf::RenderStates renderStates)
{
	this->renderStates = renderStates;
}

void Renderer::perform()
{
	this->targetWindow->draw(*this->drawable, this->renderStates);
}

Renderer* Renderer::CreateSprite(std::string name, std::string resourceName)
{
	return new SpriteRenderer(name, resourceName);
}
