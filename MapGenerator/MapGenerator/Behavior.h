
#ifndef Behavior_Class
#define Behavior_Class

#include "GameObject.h"
#include "Component.h"

class Behavior
{
public:	
	virtual void RunBehavior(GameObject * object) { };
private:
protected:
};
#endif

