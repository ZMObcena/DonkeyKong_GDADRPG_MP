#include "BarrelMovement.h"
#include "Barrel.h"

BarrelMovement::BarrelMovement(std::string name) : AComponent(name, Script)
{

}

void BarrelMovement::perform()
{
    Barrel* barrel = (Barrel*)this->getOwner();
    sf::Transformable* trans = barrel->getTransformable();

    static bool hasFallen = false;
    static int direction = 1; // Starts moving right

    bool isGrounded = barrel->isOnFloor();
    float moveSpeed = barrel->getSpeed() * this->deltaTime.asSeconds();

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
}
