#include "Collider.h"

Collider::Collider(std::string strName) : AComponent(strName, AComponent::Physics) 
{
    //this->listener = NULL;
}

void Collider::assignListener(CollisionListener* pListener) 
{
    this->listener = pListener;
}

bool Collider::hasCollisionWith(Collider* collider)
{ 
    return this->collisions.find(collider) != this->collisions.end(); 
}

void Collider::addCollision(Collider* collider)
{
    this->collisions.insert(collider);
}

void Collider::removeCollision(Collider* collider)
{
    this->collisions.erase(collider);
}

bool Collider::willCollide(Collider* pCollider) {
    sf::FloatRect A = this->getGlobalBounds();
    sf::FloatRect B = pCollider->getGlobalBounds();

    return A.intersects(B);
}

void Collider::onCollisionEnter(AGameObject* object) {
    if(this->listener != NULL) {
        this->listener->onCollisionEnter(object);
    }
}

void Collider::onCollisionExit(AGameObject* object) {
    if(this->listener != NULL) {
        this->listener->onCollisionExit(object);
    }
}

void Collider::clearCollisions()
{
    for (Collider* collider : this->collisions)
    {
        collider->onCollisionExit(this->getOwner());
        this->onCollisionExit(collider->getOwner());
        collider->removeCollision(this);
    }

    collisions.clear();
}

void Collider::setOffset(sf::FloatRect COffset) {
    this->localBounds = COffset;
}


sf::FloatRect Collider::getGlobalBounds() {
    return this->getOwner()->getGlobalTransform().transformRect(this->localBounds);
}

void Collider::perform() {}

