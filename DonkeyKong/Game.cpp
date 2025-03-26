#include "Game.h"

Game::Game() : mWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Donkey Kong"), mPlayer()
{
	mWindow.setFramerateLimit(60);

	TextureManager::getInstance()->loadAll();

	//BGObject* bgObject = new BGObject("BGObject");
	//GameObjectManager::getInstance()->addObject(bgObject);

	Player* player = new Player("Player");
	GameObjectManager::getInstance()->addObject(player);

	/*
	srand(time(nullptr));
	EmptyGameObject* enemiesManager = new EmptyGameObject("EnemiesManager");
	EnemySwarmHandler* swarmHandler = new EnemySwarmHandler(200, "SwarmHandler", enemiesManager);
	enemiesManager->attachComponent(swarmHandler);
	GameObjectManager::getInstance()->addObject(enemiesManager);
	*/


	//SceneManager::getInstance()->registerScene(new MainMenuScene());
	//SceneManager::getInstance()->loadScene(SceneManager::MAIN_MENU_SCENE_NAME);
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (mWindow.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			processEvents();
			update(TimePerFrame);	
		}
		render();
		//SceneManager::getInstance()->checkLoadScene();
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
