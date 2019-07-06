#ifndef CollisionManager_Class
#define CollisionManager_Class

#include "Box.h"
#include "GameObject.h"
#include "Point.h"
#include "CollisionHandler.h"

class CollisionManager
{
public:
	CollisionManager(GameObject ** CCObjects, int numCCObjects, GameObject ** NCCObjects, int numNCCObjects);
	void CheckCollisions();
private:
	GameObject ** CheckCollisionObjects;
	GameObject ** NoCheckCollisionObjects;
	int numCheckCollisionObjects;
	int numNoCheckCollisionObjects;

	bool SATCollision(Box * myBox, Box * otherBox);
	Point AABBCollision(Box * myBox, Box * otherBox);
protected:
};
#endif

