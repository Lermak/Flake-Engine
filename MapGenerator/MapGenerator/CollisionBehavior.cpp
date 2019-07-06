#include "CollisionBehavior.h"

CollisionBehaviors::CollisionBehaviors(const char * other, Behavior ** beh, int numBeh)
{
	this->otherTag = other;
	this->behaviors = beh;
	this->numBehaviors = numBeh;
}