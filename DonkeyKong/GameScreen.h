#pragma once

#include "AGameObject.h"
#include "UIButton.h"
#include "UIText.h"
#include <string>

class GameScreen : public AGameObject
{
public:
	GameScreen(std::string name);

	void initialize();
	void onButtonClick(UIButton* button);
	void onButtonReleased(UIButton* button);

private:
	UIButton* pauseButton;
	UIText* score;

};

