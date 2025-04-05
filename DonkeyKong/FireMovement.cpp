#include "FireMovement.h"
#include "Fire.h"
#include "TextureManager.h"

FireMovement::FireMovement(std::string name) : AComponent(name, Script)
{
    this->name = name;
}

void FireMovement::perform()
{
    Fire* fire = (Fire*)this->getOwner();
    sf::Transformable* trans = fire->getTransformable();

    isGrounded = fire->isOnFloor();
    float moveSpeed = fire->getSpeed() * this->deltaTime.asSeconds();

    animationTimer += this->deltaTime.asSeconds();

    if (animationTimer >= animationSpeed)
    {
        frameIndex = (frameIndex < 3) ? frameIndex + 1 : 1;
        animationTimer = 0.0f;
    }

    if (!isGrounded)
    {
        // Falling logic
        velocityY += gravity * this->deltaTime.asSeconds();
        trans->move(0.0f, velocityY);
        hasFallen = true;
    }
    else if (hasFallen)
    {
        // Adjust Y position to prevent clipping
        float correctionOffset = -20.0f; // Move slightly up to align with the floor
        trans->move(0.0f, correctionOffset);

        // Ensure the velocity resets upon landing
        velocityY = 0.0f;

        // Choose a new random direction after landing from a fall
        direction = (rand() % 2 == 0) ? -1 : 1;
        hasFallen = false;
    }

    // Move in chosen direction if grounded
    if (isGrounded)
    {
        trans->move(direction * moveSpeed, 0.0f);
    }

    if (direction == 1)
    {
        fire->getSprite()->setScale(2.f, 2.f);
    }
    else
    {
        fire->getSprite()->setScale(-2.f, 2.f);
    }

    fire->getSprite()->setTextureRect(TextureManager::getInstance()->getSpriteRect("Fire", frameIndex));
}

void FireMovement::reset()
{
    velocityY = 0.0f;
    hasFallen = false;
    isGrounded = false;  // Reset grounding state
    direction = (rand() % 2 == 0) ? -1 : 1;       // Reset to a default direction (or randomize)
    animationTimer = 0.0f;
    frameIndex = 1;
}