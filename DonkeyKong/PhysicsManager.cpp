#include "PhysicsManager.h"
#include <iostream>

PhysicsManager* PhysicsManager::sharedInstance = nullptr;

void PhysicsManager::initialize(std::string name, AGameObject* parent)
{
	sharedInstance = new PhysicsManager(name);
	parent->attachComponent(sharedInstance);
}

PhysicsManager* PhysicsManager::getInstance()
{
	return sharedInstance;
}

void PhysicsManager::trackObject(Collider* object)
{
	//object->clearCollisions();
	this->trackedObjects.push_back(object);
}

void PhysicsManager::untrackObject(Collider* object)
{
	this->forCleaningObjects.push_back(object);
}

void PhysicsManager::perform()
{
	for (int i = 0; i < this->trackedObjects.size(); i++)
	{
		for (int j = i + 1; j < this->trackedObjects.size(); j++)
		{
			if (this->trackedObjects[i]->getOwner()->isEnabled() &&
				this->trackedObjects[j]->getOwner()->isEnabled())
			{
				if (this->trackedObjects[i]->willCollide(this->trackedObjects[j]))
				{
					if (!this->trackedObjects[i]->hasCollisionWith(this->trackedObjects[j]))
					{
						this->trackedObjects[i]->addCollision(this->trackedObjects[j]);
						this->trackedObjects[i]->onCollisionEnter(this->trackedObjects[j]->getOwner());
					}
					if (!this->trackedObjects[j]->hasCollisionWith(this->trackedObjects[i]))
					{
						this->trackedObjects[j]->addCollision(this->trackedObjects[i]);
						this->trackedObjects[j]->onCollisionEnter(this->trackedObjects[i]->getOwner());
					}
				}
				else
				{
					if (this->trackedObjects[i]->hasCollisionWith(this->trackedObjects[j]))
					{
						this->trackedObjects[i]->onCollisionExit(this->trackedObjects[j]->getOwner());
						this->trackedObjects[i]->removeCollision(this->trackedObjects[j]);
					}
					if (this->trackedObjects[j]->hasCollisionWith(this->trackedObjects[i]))
					{
						this->trackedObjects[j]->onCollisionExit(this->trackedObjects[i]->getOwner());
						this->trackedObjects[j]->removeCollision(this->trackedObjects[i]);
					}
				}
			}
		}
	}

	this->cleanUpObjects();
}

void PhysicsManager::cleanUpObjects()
{
	for (int i = 0; i < this->forCleaningObjects.size(); i++)
	{
		for (int j = 0; j < this->forCleaningObjects.size(); j++)
		{
			if (this->forCleaningObjects[i] == this->trackedObjects[j])
			{
				this->trackedObjects.erase(this->trackedObjects.begin() + j);
			}
		}
	}

	this->forCleaningObjects.clear();
}

