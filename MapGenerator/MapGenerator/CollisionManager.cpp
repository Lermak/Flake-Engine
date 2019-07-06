#include "CollisionManager.h"

CollisionManager::CollisionManager(GameObject ** CCObjects, int numCCObjects, GameObject ** NCCObjects, int numNCCObjects)
{
	this->CheckCollisionObjects = CCObjects;
	this->NoCheckCollisionObjects = NCCObjects;
	this->numCheckCollisionObjects = numCCObjects;
	this->numNoCheckCollisionObjects = numNCCObjects;
}

bool CollisionManager::SATCollision(Box * myBox, Box * otherBox)
{

}

Point CollisionManager::AABBCollision(Box * myBox, Box * otherBox)
{
	Box mBox = (*myBox);
	if ((*myBox).BottomLeft().x > (*otherBox).BottomLeft().x &&
		(*myBox).BottomLeft().x < (*otherBox).BottomRight().x &&
		(*myBox).BottomLeft().y > (*otherBox).BottomLeft().y &&
		(*myBox).BottomLeft().y < (*otherBox).TopLeft.y)
	{
		//bottom left collision occured
		return Point(0,0);
	}
	if ((*myBox).BottomRight().x < (*otherBox).BottomRight().x &&
		(*myBox).BottomRight().x > (*otherBox).BottomLeft().x &&
		(*myBox).BottomRight().y > (*otherBox).BottomLeft().y &&
		(*myBox).BottomRight().y < (*otherBox).TopLeft.y)
	{
		//bottom right collision occured
		return Point(0, 0);
	}
	if ((*myBox).TopLeft().x > (*otherBox).BottomLeft().x &&
		(*myBox).TopLeft().x < (*otherBox).BottomRight().x &&
		(*myBox).TopLeft().y > (*otherBox).BottomLeft().y &&
		(*myBox).TopLeft().y < (*otherBox).TopLeft.y)
	{
		//top left collision occured
		return Point(0, 0);
	}
	if ((*myBox).TopRight().x > (*otherBox).BottomLeft().x &&
		(*myBox).TopRight().x < (*otherBox).BottomRight().x &&
		(*myBox).TopRight().y > (*otherBox).BottomLeft().y &&
		(*myBox).TopRight().y < (*otherBox).TopLeft.y)
	{
		//top Right collision occured
		return Point(0, 0);
	}
	
	return Point(0, 0);
}

void CollisionManager::CheckCollisions()
{
	for (int i = 0; i < this->numCheckCollisionObjects; ++i)
	{
		for (int y = 0; y < this->numNoCheckCollisionObjects; ++y)
		{
			Point p;
			p = AABBCollision(((Box *)(this->CheckCollisionObjects[i]->GetComponent("Box"))), ((Box *)(this->NoCheckCollisionObjects[y]->GetComponent("Box"))));
			if (p.x != 0 && p.y != 0)
			{
				//run appropriate behaviors for the collisionHandler on this object
				((CollisionHandler *)(this->CheckCollisionObjects[i]->GetComponent("CollisionHandler")))->RunBehaviors(this->NoCheckCollisionObjects[y]);
			}
		}
		for (int y = 0; y < this->numCheckCollisionObjects; ++y)
		{
			if (this->CheckCollisionObjects[i] != this->CheckCollisionObjects[y])//you don't collide with yourself
			{
				Point p;
				p = AABBCollision(((Box *)(this->CheckCollisionObjects[i]->GetComponent("Box"))), ((Box *)(this->CheckCollisionObjects[y]->GetComponent("Box"))));
				if (p.x != 0 && p.y != 0)
				{
					//run appropriate behaviors for the collisionHandler on this object
					((CollisionHandler *)(this->CheckCollisionObjects[i]->GetComponent("CollisionHandler")))->RunBehaviors(this->CheckCollisionObjects[y]);
				}
			}
		}
	}
}