#pragma once

#include "AComponent.h"
#include "AGameObject.h"
#include <unordered_map>
#include <vector>
#include "Collider.h"

typedef std::vector<Collider*> CollisionList;

class PhysicsManager : public AComponent
{
public:
	static void initialize(std::string name, AGameObject* parent);
	static PhysicsManager* getInstance();

	void trackObject(Collider* object);
	void untrackObject(Collider* object);
	void perform();

private:
	PhysicsManager(std::string name) : AComponent(name, Script) {};
	PhysicsManager(PhysicsManager const&) : AComponent(name, Script) {};
	PhysicsManager& operator = (PhysicsManager const&) {};
	static PhysicsManager* sharedInstance;

	CollisionList trackedObjects;
	CollisionList forCleaningObjects;

	void cleanupObjects();
};

