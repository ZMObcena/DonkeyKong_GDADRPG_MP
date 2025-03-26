#pragma once
#include "AComponent.h"

class GenericInputController : public AComponent
{
public: 
	GenericInputController(std::string name);
	~GenericInputController();

	void perform();
	void assignEvent(sf::Event event);

protected:
	sf::Event event;
};

