#include "PlayerMovement.h"

PlayerMovement::PlayerMovement(std::string name) : AComponent(name, Script)
{

}

void PlayerMovement::perform()
{
    Player* player = (Player*)GameObjectManager::getInstance()->findObjectByName("Player");
    PlayerInputController* input = (PlayerInputController*)this->getOwner()->findComponentByName(player->getName() + " Input");
    sf::Transformable* trans = player->getTransformable();

	if (input == nullptr)
	{
		std::cout << "playerTransformable not found" << std::endl;
	}

	sf::Vector2f offset(0.0f, 0.0f);

    float fSpeed = player->getSpeed();
    float fOffset = fSpeed * this->deltaTime.asSeconds();

    if (input->isUp())
    {
        trans->move(0.0f, -fOffset);
        std::cout << "Moving up";
    }

    if (input->isDown())
        trans->move(0.0f, fOffset);

    if (input->isLeft())
        trans->move(-fOffset, 0.0f);

    if (input->isRight())
        trans->move(fOffset, 0.0f);
}
