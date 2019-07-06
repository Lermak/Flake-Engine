#ifndef CollisionHandler_Class
#define CollisionHandler_Class

#include "GameObject.h"
#include "Component.h"
#include "Behavior.h"
#include "CollisionBehavior.h"

class CollisionHandler : public Component
{	
public:
	CollisionHandler(GameObject * myObject, CollisionBehaviors ** myBeh, int numBeh);
	void RunBehaviors(GameObject * collidedWith);
private:
	CollisionBehaviors ** myBehaviors;
	int numCollisionBehaviors;
protected:
};
#endif

#pragma once
