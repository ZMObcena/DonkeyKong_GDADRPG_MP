#include "PlayerInputController.h"
#include "SceneManager.h"
#include "SFXManager.h"

PlayerInputController::PlayerInputController(std::string name) : GenericInputController(name)
{

}

PlayerInputController::~PlayerInputController()
{
	GenericInputController::~GenericInputController();
}

void PlayerInputController::perform()
{
    switch (this->event.type) 
    {
    case sf::Event::KeyPressed:
        this->processKeyInput(true);
        break;

    case sf::Event::KeyReleased:
        this->processKeyInput(false);
        break;

    default:
        break;
    }
}

void PlayerInputController::processKeyInput(bool pressed)
{
    sf::Keyboard::Key key = this->event.key.code;

    bool wasWalking = moveUp || moveDown || moveLeft || moveRight;

    switch (key) {

    case sf::Keyboard::Space:
        this->jump = pressed;
        SFXManager::getInstance()->playSound("jump");
        break;

    case sf::Keyboard::W:
        this->moveUp = pressed;
        break;

    case sf::Keyboard::S:
        this->moveDown = pressed;
        break;

    case sf::Keyboard::A:
        this->moveLeft = pressed;
        break;

    case sf::Keyboard::D:
        this->moveRight = pressed;
        break;

    // FOR TESTING ONLY
    case sf::Keyboard::Num0:
        SceneManager::getInstance()->loadScene(SceneManager::MAIN_MENU_SCENE);
        break;

    case sf::Keyboard::Num1:
        SceneManager::getInstance()->loadScene(SceneManager::LEVEL_1_SCENE);
        break;

    case sf::Keyboard::Num2:
        SceneManager::getInstance()->loadScene(SceneManager::LEVEL_2_SCENE);
        break;

    case sf::Keyboard::Num3:
        SceneManager::getInstance()->loadScene(SceneManager::LEVEL_3_SCENE);
        break;

    case sf::Keyboard::Num4:
        SceneManager::getInstance()->loadScene(SceneManager::RESULTS_SCENE);
        break;
    default:
        break;
    }

    bool isWalking = moveUp || moveDown || moveLeft || moveRight;
    SFXManager* sfx = SFXManager::getInstance();

    if (isWalking && !sfx->isPlaying("walking2"))
    {
        sfx->playSound("walking2");
    }
    else if (!isWalking && wasWalking)
    {
        sfx->stopPlaying("walking2");
    }
}

bool PlayerInputController::isUp()
{
	return moveUp;
}

bool PlayerInputController::isDown()
{
	return moveDown;
}

bool PlayerInputController::isRight()
{
	return moveRight;
}

bool PlayerInputController::isLeft()
{
	return moveLeft;
}

bool PlayerInputController::isJumping()
{
    return jump;
}
