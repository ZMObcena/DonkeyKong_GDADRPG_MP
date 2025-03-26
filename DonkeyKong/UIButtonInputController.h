#pragma once

#include "GenericInputController.h"
#include "ButtonListener.h"
#include "UIButton.h"

class UIButtonInputController : public GenericInputController
{
public:
	UIButtonInputController(std::string name, ButtonListener* listener);
	~UIButtonInputController();

	void perform();

private:
	ButtonListener* listener;
	bool pressed = false;
};

