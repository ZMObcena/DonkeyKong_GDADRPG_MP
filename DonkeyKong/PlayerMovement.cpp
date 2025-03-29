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
    static sf::Vector2f previousSize(0.0f, 0.0f);

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
    //sf::Vector2f currentSize(spriteRect.width, spriteRect.height);
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
        jumpDirection = 0.0f;
    }

    bool movingHorizontally = false;

    if (!isJumping || isUsingHammer)
    {
        if (input->isLeft())
        {
            trans->move(-fOffset, 0.0f);
            jumpDirection = -fOffset;
            movingHorizontally = true;

            animationTimer += this->deltaTime.asSeconds();
            if (animationTimer >= animationSpeed)
            {
                if (isUsingHammer)
                {
                    int frames[] = { 3, 6 };
                    frameIndex = frames[animationStep];
                    animationStep = (animationStep + 1) % 2;
                    animationTimer = 0.0f;
                }
                else
                {
                    int frames[] = { 7, 8, 9 };
                    frameIndex = frames[animationStep];
                    animationStep = (animationStep + 1) % 3;
                    animationTimer = 0.0f;
                }
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
            movingHorizontally = true;

            animationTimer += this->deltaTime.asSeconds();
            if (animationTimer >= animationSpeed)
            {
                if (isUsingHammer)
                {
                    int frames[] = { 3, 6 };
                    frameIndex = frames[animationStep];
                    animationStep = (animationStep + 1) % 2;
                    animationTimer = 0.0f;
                }
                else
                {
                    int frames[] = { 7, 8, 9 };
                    frameIndex = frames[animationStep];
                    animationStep = (animationStep + 1) % 3;
                    animationTimer = 0.0f;
                }
            }

            if (!player->facingRight)
            {
                player->facingRight = true;
                trans->move(bounds.width, 0.0f);
            }
            player->getSprite()->setScale(-3.0f, 3.0f);
        }

        if (!movingHorizontally)
        {
            if (isUsingHammer)
            {
                frameIndex = 3;
            }
            else
            {
                frameIndex = 7;
                animationStep = 0;
            }
        }
    }
    else
    {
        trans->move(jumpDirection, 0.0f);
        frameIndex = 9;
    }

    if (input->isJumping() && isGrounded && !isOnLadder && !isUsingHammer)
    {
        isJumping = true;
        velocityY = jumpStrength;
        frameIndex = 9;
    }

    if ((!isGrounded || isJumping) && !isOnLadder && !isUsingHammer)
    {
        velocityY += gravity * this->deltaTime.asSeconds();
        trans->move(0.0f, velocityY * this->deltaTime.asSeconds());
    }

    player->getSprite()->setTextureRect(TextureManager::getInstance()->getSpriteRect("Mario", frameIndex));
}
