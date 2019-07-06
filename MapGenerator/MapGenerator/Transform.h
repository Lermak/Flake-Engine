#ifndef Transform_Class
#define Transform_Class

#include "GameObject.h"
#include "Component.h"
#include "Point.h"
class Transform : public Component
{
public:
	Transform(Point point, float rotate, GameObject * object);
	Point GetWorldPos();
	float GetRotation();
	void UpdateRotation(float degrees);
	void UpdateWorldPos(float x, float y);
private:
	Point worldPos;
	float rotation;
protected:
};
#endif

