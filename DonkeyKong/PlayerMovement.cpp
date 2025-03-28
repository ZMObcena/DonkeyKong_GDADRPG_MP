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

    float fSpeed = player->getSpeed();
    float fOffset = fSpeed * this->deltaTime.asSeconds();

    bool isGrounded = player->isOnFloor();
    bool isOnLadder = player->isOnLadder();

    static int frameIndex = 7; // Default idle frame
    static float animationTimer = 0.0f;
    const float animationSpeed = 0.08f;
    static int animationStep = 0; // Controls animation sequence

    sf::FloatRect bounds = player->getSprite()->getLocalBounds();
    player->getSprite()->setOrigin(bounds.width / 2, bounds.height / 2);

    if (isGrounded)
    {
        isJumping = false;
        velocityY = 0.0f; // Reset vertical velocity when on ground
        jumpDirection = 0.0f;
    }

    // Ladder Movement
    if (input->isUp() && isOnLadder)
    {
        trans->move(0.0f, -fOffset);
    }
    if (input->isDown() && isOnLadder)
    {
        trans->move(0.0f, fOffset);
    }

    // Horizontal Movement (Maintain jump direction mid-air)
    bool movingHorizontally = false;

    if (!isJumping)
    {
        if (input->isLeft())
        {
            trans->move(-fOffset, 0.0f);
            jumpDirection = -fOffset; // Store direction
            movingHorizontally = true;

            animationTimer += this->deltaTime.asSeconds();
            if (animationTimer >= animationSpeed)
            {
                int frames[] = { 7, 8, 9, 8 };
                frameIndex = frames[animationStep];
                animationStep = (animationStep + 1) % 4;
                animationTimer = 0.0f;
            }

            if (player->facingRight)
            {
                player->facingRight = false;
                trans->move(-bounds.width, 0.0f); // Adjust position when flipping
            }
            player->getSprite()->setScale(3.0f, 3.0f); // Flip sprite left
        }
        else if (input->isRight())
        {
            trans->move(fOffset, 0.0f);
            jumpDirection = fOffset; // Store direction
            movingHorizontally = true;

            animationTimer += this->deltaTime.asSeconds();
            if (animationTimer >= animationSpeed)
            {
                int frames[] = { 7, 8, 9, 8 };
                frameIndex = frames[animationStep];
                animationStep = (animationStep + 1) % 4;
                animationTimer = 0.0f;
            }

            if (!player->facingRight)
            {
                player->facingRight = true;
                trans->move(bounds.width, 0.0f); // Adjust position when flipping
            }
            player->getSprite()->setScale(-3.0f, 3.0f); // Flip
        }

        if (!movingHorizontally)
        {
            frameIndex = 7; // Idle frame
            animationStep = 0; // Reset animation cycle
        }
    }
    else // If jumping, maintain direction
    {
        trans->move(jumpDirection, 0.0f);
        frameIndex = 9; // Jump frame
    }

    // Jumping Logic
    if (input->isJumping() && isGrounded && !isOnLadder)
    {
        isJumping = true;
        velocityY = jumpStrength;
        frameIndex = 9; // Set jump frame
    }

    // Apply Gravity
    if (!isGrounded || isJumping && !isOnLadder)
    {
        velocityY += gravity * this->deltaTime.asSeconds();
        trans->move(0.0f, velocityY * this->deltaTime.asSeconds());
    }

    // Update Sprite Animation
    player->getSprite()->setTextureRect(TextureManager::getInstance()->getSpriteRect("Mario", frameIndex));
}


