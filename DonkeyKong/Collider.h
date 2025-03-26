#pragma once

#include "CollisionListener.h"
#include "AComponent.h"
#include "AGameObject.h"

class Collider : public AComponent
{
public:
    Collider(std::string strName);

    void assignListener(CollisionListener* pListener);

    void setChecked(bool flag);
    bool isChecked();


    bool willCollide(Collider* pCollider);
    bool hasCollided();
    void setCollided(bool bCollided);

    sf::FloatRect getGlobalBounds();
    void setOffset(sf::FloatRect COffset);
    void onCollisionEnter(AGameObject* pCollider);
    void onCollisionExit(AGameObject* pCollider);

    void perform();

private:
    bool collided = false;
    bool checked = false;
    sf::FloatRect localBounds;
    CollisionListener* listener;
};

