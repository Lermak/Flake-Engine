#include "BehaviorHandler.h"

BehaviorHandler::BehaviorHandler(Behavior ** myBehaviors, int numBeh, GameObject * object) : Component(object)
{
	this->tag = "BehaviorHandler";
	this->numBehaviors = numBeh;
	this->myBehaviorList = myBehaviors;
}

void BehaviorHandler::RunBehaviors()
{
	for (int i = 0; i < numBehaviors; ++i)
	{
		myBehaviorList[i]->RunBehavior(MyObject);
	}
}