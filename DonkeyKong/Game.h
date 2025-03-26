#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"

#include "GameObjectManager.h"
#include "SceneManager.h"
#include "TextureManager.h"
#include "MainMenuScene.h"
#include "ApplicationManager.h"

#include "BGObject.h"
#include "Player.h"

#include "IEventListener.h"

class Game : public IEventListener
{
public:
	Game();

	void OnEventTrigger(EventKeys eventName, Parameters params);
	void run();
	const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
	const int WINDOW_WIDTH = 640;
	const int WINDOW_HEIGHT = 480;

private:
	void processEvents();
	void update(sf::Time time);
	void render();

private:
	sf::RenderWindow mWindow;
	sf::Texture mTexture;
	sf::Sprite mPlayer;
	sf::Font mFont;
	sf::Text mFPSText;
	sf::Text mDeltaText;
	Entity mSampleEntity;


};
