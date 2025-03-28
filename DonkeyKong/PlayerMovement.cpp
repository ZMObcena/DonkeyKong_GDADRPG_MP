#include "PlayerMovement.h"

PlayerMovement::PlayerMovement(std::string name) : AComponent(name, Script)
{

}

void PlayerMovement::perform()
{
    Player* player = (Player*)this->getOwner();
    PlayerInputController* input = (PlayerInputController*)this->getOwner()->findComponentByName(player->getName() + " Input");
    sf::Transformable* trans = player->getTransformable();

	sf::Vector2f offset(0.0f, 0.0f);
    sf::Vector2f oldPos = trans->getPosition();

    float fSpeed = player->getSpeed();
    float fOffset = fSpeed * this->deltaTime.asSeconds();

    bool isGrounded = player->isOnFloor();
    bool isOnLadder = player->isOnLadder();

    if (isGrounded)
    {
        isJumping = false;
        velocityY = 0.0f; // Reset vertical velocity when on ground
        jumpDirection = 0.0f;
    }

     //Ladder Movement
    if (input->isUp() && isOnLadder)
    {
        trans->move(0.0f, -fOffset);
    }
    if (input->isDown() && isOnLadder)
    {
        trans->move(0.0f, fOffset);
    }

    // Horizontal Movement (Maintain jump direction mid-air)
    if (!isJumping)
    {
        if (input->isLeft())
        {
            trans->move(-fOffset, 0.0f);
            jumpDirection = -fOffset; // Store direction
        }
        if (input->isRight())
        {
            trans->move(fOffset, 0.0f);
            jumpDirection = fOffset; // Store direction
        }
    }
    else // If jumping, maintain direction
    {
        trans->move(jumpDirection, 0.0f);
    }

    // Jumping Logic
    if (input->isJumping() && isGrounded && !isOnLadder)
    {
        isJumping = true;
        velocityY = jumpStrength;
    }

    // Apply Gravity
    if (!isGrounded || isJumping && !isOnLadder)
    {
        velocityY += gravity * this->deltaTime.asSeconds();
        trans->move(0.0f, velocityY * this->deltaTime.asSeconds());
    }
}
