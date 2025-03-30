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
    bool isUsingHammer = player->isUsingHammer();

    static int frameIndex = 7; // Default idle frame
    static float animationTimer = 0.0f;
    static float hammerTimer = 0.0f;
    const float animationSpeed = 0.08f;
    static int animationStep = 0;
    static bool lockedToLadder = false;

    if (isUsingHammer)
    {
        hammerTimer += this->deltaTime.asSeconds();
        if (hammerTimer >= 10.0f)
        {
            player->setUsingHammer(false);
            hammerTimer = 0.0f;
        }
    }

    sf::IntRect spriteRect = TextureManager::getInstance()->getSpriteRect("Mario", frameIndex);
    sf::FloatRect bounds(spriteRect);
    sf::Vector2f spriteOrigin(bounds.width / 2, bounds.height / 2);

    if (frameIndex == 2)
    {
        spriteOrigin.x -= 20.0f; // Shift sprite slightly right
        spriteOrigin.y += 1.0f; // Shift sprite slightly down
    }

    if (isGrounded)
    {
        isJumping = false;
        velocityY = 0.0f;
        jumpDirection = 0.0f; // Reset jump direction when on ground
        lockedToLadder = false;
    }

    bool movingVertically = false;

    if (isOnLadder && !isUsingHammer)
    {
        velocityY = 0.0f; // Stop gravity while on ladder
        isJumping = false; // Prevent jumping
        jumpDirection = 0.0f; // No horizontal movement when climbing

        if (input->isUp() || input->isDown())
        {
            lockedToLadder = true;
        }
        if (input->isUp())
        {
            trans->move(0.0f, -fOffset / 2);
            movingVertically = true;

            animationTimer += this->deltaTime.asSeconds();
            if (animationTimer >= animationSpeed)
            {
                int frames[] = { 0, 1 };
                frameIndex = frames[animationStep];
                animationStep = (animationStep + 1) % 2;
                animationTimer = 0.0f;
            }
        }
        else if (input->isDown())
        {
            trans->move(0.0f, fOffset / 2);
            movingVertically = true;

            animationTimer += this->deltaTime.asSeconds();
            if (animationTimer >= animationSpeed)
            {
                int frames[] = { 0, 1 };
                frameIndex = frames[animationStep];
                animationStep = (animationStep + 1) % 2;
                animationTimer = 0.0f;
            }
        }
    }

    if (!isOnLadder || !lockedToLadder) // Allow left and right movement only if not climbing
    {
        if (!isJumping || isUsingHammer)
        {
            if (input->isLeft())
            {
                trans->move(-fOffset, 0.0f);
                jumpDirection = -fOffset;

                animationTimer += this->deltaTime.asSeconds();
                if (animationTimer >= animationSpeed)
                {
                    if (isUsingHammer)
                    {
                        int frames[] = { 3, 6 };
                        frameIndex = frames[animationStep];
                        animationStep = (animationStep + 1) % 2;
                    }
                    else
                    {
                        int frames[] = { 7, 8, 9 };
                        frameIndex = frames[animationStep];
                        animationStep = (animationStep + 1) % 3;
                    }
                    animationTimer = 0.0f;
                }

                if (player->facingRight)
                {
                    player->facingRight = false;
                    trans->move(-bounds.width, 0.0f);
                }
                player->getSprite()->setScale(3.0f, 3.0f);
            }
            else if (input->isRight())
            {
                trans->move(fOffset, 0.0f);
                jumpDirection = fOffset;

                animationTimer += this->deltaTime.asSeconds();
                if (animationTimer >= animationSpeed)
                {
                    if (isUsingHammer)
                    {
                        int frames[] = { 3, 6 };
                        frameIndex = frames[animationStep];
                        animationStep = (animationStep + 1) % 2;
                    }
                    else
                    {
                        int frames[] = { 7, 8, 9 };
                        frameIndex = frames[animationStep];
                        animationStep = (animationStep + 1) % 3;
                    }
                    animationTimer = 0.0f;
                }

                if (!player->facingRight)
                {
                    player->facingRight = true;
                    trans->move(bounds.width, 0.0f);
                }
                player->getSprite()->setScale(-3.0f, 3.0f);
            }
        }
    }

    if (input->isJumping() && isGrounded && !isOnLadder && !isUsingHammer)
    {
        isJumping = true;
        velocityY = jumpStrength;
        frameIndex = 9;
        if (jumpDirection == 0.0f) // Ensure vertical jump if idle
        {
            trans->move(0.0f, velocityY * this->deltaTime.asSeconds());
        }
    }

    if (jumpDirection == 0.0f)
    {
        //animationTimer += this->deltaTime.asSeconds();

        if (!isOnLadder)
        {
            frameIndex = 7;
        }
        if (isJumping)
        {
            frameIndex = 9;
        }
        if (isUsingHammer)
        {
            frameIndex = 3;
        }

    }

    if ((!isGrounded || isJumping) && !isOnLadder)
    {
        velocityY += gravity * this->deltaTime.asSeconds();
        trans->move(jumpDirection, velocityY * this->deltaTime.asSeconds());
    }

    player->getSprite()->setTextureRect(TextureManager::getInstance()->getSpriteRect("Mario", frameIndex));
}
