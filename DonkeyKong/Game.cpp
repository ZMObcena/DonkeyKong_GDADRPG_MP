#include "Game.h"

Game::Game() : mWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Airplane"), mPlayer()
{
	mWindow.setFramerateLimit(60);
	TextureManager::getInstance()->loadAll();

	BGObject* bgObject = new BGObject("BGObject");
	GameObjectManager::getInstance()->addObject(bgObject);

	Player* player = new Player("Player");
	GameObjectManager::getInstance()->addObject(player);
	//player->setPosition(200, 200);

	//AirplaneSupport* support1 = new AirplaneSupport("AirSupport_1");
	//player->attachChild(support1);
	//support1->setPosition(50, 100);

	//AirplaneSupport* support2 = new AirplaneSupport("AirSupport_2");
	//player->attachChild(support2);
	//support1->setPosition(50, 100);

	/*
	srand(time(nullptr));
	EmptyGameObject* enemiesManager = new EmptyGameObject("EnemiesManager");
	EnemySwarmHandler* swarmHandler = new EnemySwarmHandler(200, "SwarmHandler", enemiesManager);
	enemiesManager->attachComponent(swarmHandler);
	GameObjectManager::getInstance()->addObject(enemiesManager);
	*/
}

void Game::run()
{
	sf::Clock clock;

	while (mWindow.isOpen())
	{
		sf::Time deltaTime = clock.restart();

		processEvents();
		update(deltaTime);
		render();
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
	GameObjectManager::getInstance()->update(deltaTime);
}

