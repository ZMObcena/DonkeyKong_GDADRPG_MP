#include "BarrelMovement.h"
#include "Barrel.h"

BarrelMovement::BarrelMovement(std::string name) : AComponent(name, Script)
{

}

void BarrelMovement::perform()
{
    Barrel* barrel = (Barrel*)this->getOwner();
    sf::Transformable* trans = barrel->getTransformable();

    bool isGrounded = barrel->isOnFloor();
    float moveSpeed = barrel->getSpeed() * this->deltaTime.asSeconds();

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
        float correctionOffset = -20.0f; // Move slightly up to align with the floor
        trans->move(0.0f, correctionOffset);

        velocityY = 0.0f;

        // Choose a new random direction after landing from a fall
        direction = (rand() % 2 == 0) ? -1 : 1;
        hasFallen = false;
    }

    // Move in chosen direction if grounded
    if (isGrounded)
    {
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
