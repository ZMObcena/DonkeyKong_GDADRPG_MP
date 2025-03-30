#include "DonkeyKongMovement.h"
#include "DonkeyKong.h"
#include "ObjectPoolHolder.h"
#include <random>

std::random_device rdDK;
std::mt19937 dkgen(rdDK());
std::uniform_real_distribution<float> attackDist(0.01f, 3.f); // Adjust range as needed

DonkeyKongMovement::DonkeyKongMovement(std::string name) : AComponent(name, Script)
{

}

void DonkeyKongMovement::perform()
{
    DonkeyKong* dk = (DonkeyKong*)this->getOwner();

    static int frameIndex = 0;
    static float animationTimer = 0.0f;
    static float attackTimer = 0.0f;
    static float nextAttackTime = attackDist(dkgen);
    const float animationSpeed = 0.1f;
    //float animationSpeed = nextAttackTime;
    static bool isAttacking = false;
    static int attackStep = 0;
    static bool hasSpawned = false;

    animationTimer += this->deltaTime.asSeconds();
    attackTimer += this->deltaTime.asSeconds();

    if (frameIndex == 4 && !hasSpawned)
    {
        GameObjectPool* barrelPool = ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::BARREL_POOL_TAG);
        barrelPool->requestPoolable();
        hasSpawned = true;
    }

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
                nextAttackTime = attackDist(dkgen); // Reset attack timer
                //animationSpeed = nextAttackTime;
                hasSpawned = false;
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
