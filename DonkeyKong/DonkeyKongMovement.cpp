#include "DonkeyKongMovement.h"
#include "DonkeyKong.h"

DonkeyKongMovement::DonkeyKongMovement(std::string name) : AComponent(name, Script)
{

}

void DonkeyKongMovement::perform()
{
    DonkeyKong* dk = (DonkeyKong*)this->getOwner();
    static int frameIndex = 0;
    static float animationTimer = 0.0f;
    static float attackTimer = 0.0f;
    static float nextAttackTime = (rand() % 2 + 1.5f); // Random interval between 1.5 to 3 seconds
    const float animationSpeed = 0.18f;
    static bool isAttacking = false;
    static int attackStep = 0;

    animationTimer += this->deltaTime.asSeconds();
    attackTimer += this->deltaTime.asSeconds();

    if (isAttacking)
    {
        if (animationTimer >= animationSpeed)
        {
            int attackFrames[] = { 2, 3, 4 };
            frameIndex = attackFrames[attackStep];
            attackStep++;
            animationTimer = 0.0f;

            if (attackStep >= 4) // End attack sequence
            {
                isAttacking = false;
                attackStep = 0;
                frameIndex = 0; // Return to idle
                attackTimer = 0.0f;
                nextAttackTime = (rand() % 2 + 1.5f); // Reset attack timer
            }
        }
    }
    else
    {
        if (attackTimer >= nextAttackTime)
        {
            isAttacking = true;
            attackStep = 0;
            attackTimer = 0.0f;
        }
        else if (animationTimer >= animationSpeed)
        {
            frameIndex = (frameIndex == 0) ? 1 : 0; // Idle animation loop
            animationTimer = 0.0f;
        }
    }

    dk->getSprite()->setTextureRect(TextureManager::getInstance()->getSpriteRect("DonkeyKong", frameIndex));
}
