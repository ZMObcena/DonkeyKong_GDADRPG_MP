#include "Renderer.h"

Renderer::Renderer(std::string name) : AComponent(name, AComponent::Renderer)
{

}

Renderer::~Renderer()
{
	if (this->drawable != nullptr)
	{
		delete this->drawable;
	}

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
