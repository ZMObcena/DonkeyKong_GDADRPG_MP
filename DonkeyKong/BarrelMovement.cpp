#include "BarrelMovement.h"
#include "Barrel.h"
#include "ObjectPoolHolder.h"
#include "GameObjectPool.h"
#include <random>



BarrelMovement::BarrelMovement(std::string name) : AComponent(name, Script)
{

}

void BarrelMovement::perform()
{
    Barrel* barrel = (Barrel*)this->getOwner();
    sf::Transformable* trans = barrel->getTransformable();


    isGrounded = barrel->isOnFloor();
    float moveSpeed = barrel->getSpeed()  * this->deltaTime.asSeconds();

    animationTimer += this->deltaTime.asSeconds();

    if (!isGrounded)
    {
        // Falling logic
        velocityY += gravity * this->deltaTime.asSeconds();
        trans->move(0.0f, velocityY);
        hasFallen = true;

        // Animate falling frames (5 -> 6 loop)
        if (animationTimer >= animationSpeed)
        {
            frameIndex = (frameIndex == 5) ? 6 : 5;
            animationTimer = 0.0f;
        }
    }
    else if (hasFallen)
    {
        // Adjust Y position to prevent clipping
        trans->move(0.0f, correctionOffset);

        velocityY = 0.0f;

        // Choose a new random direction after landing from a fall
        direction = (rand() % 2 == 0) ? -1 : 1;
        hasFallen = false;
    }

    // Move in chosen direction if grounded
    if (isGrounded)
    {
        //fallTimer = 0.0f;
        trans->move(direction * moveSpeed, 0.0f);

        // Animate rolling frames (1 -> 2 -> 3 -> 4 loop)
        if (animationTimer >= animationSpeed)
        {
            frameIndex = (frameIndex < 4) ? frameIndex + 1 : 1;
            animationTimer = 0.0f;
        }
    }

    // Update Sprite Animation
    barrel->getSprite()->setTextureRect(TextureManager::getInstance()->getSpriteRect("Barrel", frameIndex));
}

void BarrelMovement::reset()
{
    velocityY = 0.0f;
    hasFallen = false;
    isGrounded = false;  // Reset grounding state
    direction = 1;       // Reset to a default direction (or randomize)
    animationTimer = 0.0f;
    frameIndex = 1;
}