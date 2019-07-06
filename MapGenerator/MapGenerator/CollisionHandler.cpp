#include "CollisionHandler.h"

CollisionHandler::CollisionHandler(GameObject * myObject, CollisionBehaviors ** myBeh, int numBeh) : Component(myObject)
{
	this->tag = "CollisionHandler";
	this->myBehaviors = myBeh;
	this->numCollisionBehaviors = numBeh;
}

void CollisionHandler::RunBehaviors(GameObject * collidedWith)
{
	for (int i = 0; i < numCollisionBehaviors; ++i)
	{
		if (myBehaviors[i]->otherObject = collidedWith)
		{
			for (int y = 0; y < myBehaviors[i]->numBehaviors; ++y)
			{
				myBehaviors[i]->behaviors[y]->RunBehavior(MyObject);
			}
		}
	}
}