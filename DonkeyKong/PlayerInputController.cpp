#include "PlayerInputController.h"

PlayerInputController::PlayerInputController(std::string name) : GenericInputController(name)
{

}

PlayerInputController::~PlayerInputController()
{
	GenericInputController::~GenericInputController();
}

void PlayerInputController::perform()
{
    switch (this->event.type) {
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

    switch (key) {

    /*case sf::Keyboard::Space:
        this->moveUp = pressed;
        break;*/

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

    default:
        break;
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

