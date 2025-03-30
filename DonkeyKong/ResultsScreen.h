#pragma once

#include "AGameObject.h"
#include "ButtonListener.h"
#include <string>

class ResultsScreen : public AGameObject, public ButtonListener
{
public:
	ResultsScreen(std::string name);

	void initialize();
	void onButtonClick(UIButton* button);
	void onButtonReleased(UIButton* button);

private:
	UIButton* startButton;
	UIButton* exitButton;
	UIButton* logo;

};

