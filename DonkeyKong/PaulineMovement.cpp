#include "PaulineMovement.h"
#include "BGObject.h"

PaulineMovement::PaulineMovement(std::string name) : AComponent(name, Script)
{

}

void PaulineMovement::perform()
{
    BGObject* owner = (BGObject*)this->getOwner();
    sf::Sprite* sprite = owner->getSprite();

    static int frameSequence[] = { 0, 1, 3, 4, 3, 1 }; // Custom animation sequence
    static int frameIndex = 0;
    static float animationTimer = 0.0f;
    const float animationSpeed = 0.15f; // Adjust timing as needed

    int frameWidth = sprite->getTexture()->getSize().x / 5; // Assuming 5 frames in a row
    int frameHeight = sprite->getTexture()->getSize().y;

    animationTimer += this->deltaTime.asSeconds();

    if (animationTimer >= animationSpeed)
    {
        frameIndex = (frameIndex + 1) % (sizeof(frameSequence) / sizeof(frameSequence[0])); // Loop through sequence
        animationTimer = 0.0f;
    }

    sprite->setTextureRect(sf::IntRect(frameSequence[frameIndex] * frameWidth, 0, frameWidth, frameHeight));

}

