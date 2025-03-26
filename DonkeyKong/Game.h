#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "GameObjectManager.h"
#include "TextureManager.h"
#include "BGObject.h"
#include "Player.h"

class Game
{
public:
	Game();
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
