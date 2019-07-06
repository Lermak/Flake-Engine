#ifndef CollisionBehavior_Class
#define CollisionBehavior_Class
#include "Behavior.h"

class CollisionBehaviors
{
public:
	const char * otherTag;
	Behavior ** behaviors;
	CollisionBehaviors(const char * other, Behavior ** beh, int numBeh);
private:
	int numBehaviors;
protected:
};
#endif
