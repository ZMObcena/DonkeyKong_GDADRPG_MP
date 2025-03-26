#include "Collider.h"


Collider::Collider(std::string strName) : AComponent(strName, AComponent::Physics) 
{

}

void Collider::assignListener(CollisionListener* pListener) 
{
    this->listener = pListener;
}

void Collider::setChecked(bool flag)
{
    this->checked = flag;
}

bool Collider::isChecked() { return this->checked; }

bool Collider::willCollide(Collider* pCollider) {
    sf::FloatRect CBoundsA = this->getGlobalBounds();
    sf::FloatRect CBoundsB = pCollider->getGlobalBounds();

    return CBoundsA.intersects(CBoundsB);
}

bool Collider::hasCollided() { return this->collided; }

void Collider::setCollided(bool bCollided) {
    this->collided = bCollided;
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


void Collider::setOffset(sf::FloatRect COffset) {
    this->localBounds = COffset;
}


sf::FloatRect Collider::getGlobalBounds() {
    return this->getOwner()->getGlobalTransform().transformRect(this->localBounds);
}

void Collider::perform() {}