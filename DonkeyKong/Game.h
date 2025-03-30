#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"

#include "GameObjectManager.h"
#include "SceneManager.h"
#include "TextureManager.h"
#include "ApplicationManager.h"
#include "FontManager.h"
#include "PhysicsManager.h"

#include "MainMenuScene.h"
#include "ResultsScene.h"
#include "Level1Scene.h"
#include "Level2Scene.h"
#include "Level3Scene.h"

class Game 
{
public:
	Game();
	void run();
	const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
	const int WINDOW_WIDTH = 1920;
	const int WINDOW_HEIGHT = 1080;

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
