#include "Game.h"

Game::Game() : mWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Donkey Kong"), mPlayer()
{
	mWindow.setFramerateLimit(60);

	FontManager::getInstance()->loadAll();
	SceneManager::getInstance()->registerScene(new MainMenuScene());
	SceneManager::getInstance()->registerScene(new ResultsScene());
	SceneManager::getInstance()->registerScene(new Level1Scene());
	SceneManager::getInstance()->registerScene(new Level2Scene());
	SceneManager::getInstance()->registerScene(new Level3Scene());
	SceneManager::getInstance()->loadScene(SceneManager::MAIN_MENU_SCENE);
	//SceneManager::getInstance()->loadScene(SceneManager::LEVEL_3_SCENE);
}
  
void Game::run()
{
	sf::Clock clock = sf::Clock();
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (mWindow.isOpen())
	{
		this->processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			this->update(TimePerFrame);
		}
		this->render();
		SceneManager::getInstance()->checkLoadScene();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
		
		default:
			GameObjectManager::getInstance()->processInput(event);
			break;
		}
	}
}

void Game::render()
{
	mWindow.clear();
	GameObjectManager::getInstance()->draw(&mWindow);
	mWindow.display();
}

void Game::update(sf::Time deltaTime)
{
	if (!ApplicationManager::getInstance()->isPaused())
	{
		GameObjectManager::getInstance()->update(deltaTime);
	}
}
