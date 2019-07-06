#ifndef BehaviorHandler_Class
#define BehaviorHandler_Class

#include "Component.h"
#include "Behavior.h"

class BehaviorHandler : public Component
{
public:
	BehaviorHandler(Behavior ** myBehaviors, int numBeh, GameObject * object);
	void RunBehaviors();
private:
	Behavior ** myBehaviorList;
	int numBehaviors;
protected:
};
#endif

#pragma once
