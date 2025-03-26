#pragma once

#include "CollisionListener.h"
#include "AComponent.h"
#include "AGameObject.h"
#include <unordered_set>

class Collider : public AComponent
{
public:
    Collider(std::string strName);

    void assignListener(CollisionListener* pListener);

    bool willCollide(Collider* pCollider);
    bool hasCollisionWith(Collider* collider);
    void addCollision(Collider* collider);
    void removeCollision(Collider* collider);

    sf::FloatRect getGlobalBounds();
    void setOffset(sf::FloatRect COffset);
    void onCollisionEnter(AGameObject* pCollider);
    void onCollisionExit(AGameObject* pCollider);

    void perform();
    void clearCollisions();

private:
    bool checked = false;
    std::unordered_set<Collider*> collisions;
    sf::FloatRect localBounds;
    CollisionListener* listener;
};

