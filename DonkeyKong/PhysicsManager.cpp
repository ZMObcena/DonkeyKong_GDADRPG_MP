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
	object->setCollided(false);
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
		for (int j = 0; j < this->trackedObjects.size(); j++)
		{
			if (this->trackedObjects[i] != this->trackedObjects[j] &&
				this->trackedObjects[i]->getOwner()->isEnabled() &&
				this->trackedObjects[j]->getOwner()->isEnabled())
			{
				if (this->trackedObjects[i]->willCollide(this->trackedObjects[j]))
				{
					this->trackedObjects[i]->onCollisionEnter(this->trackedObjects[j]->getOwner());
					this->trackedObjects[j]->onCollisionEnter(this->trackedObjects[i]->getOwner());
				}
			}
		}
	}

	this->cleanupObjects();
}

void PhysicsManager::cleanupObjects()
{
	for (int i = 0; i < this->forCleaningObjects.size(); i++)
	{
		for (int j = 0; j < this->trackedObjects.size(); j++)
		{
			if (this->forCleaningObjects[i] == this->trackedObjects[j])
			{
				this->trackedObjects.erase(this->trackedObjects.begin() + j);
			}
		}
	}

	this->forCleaningObjects.clear();
}