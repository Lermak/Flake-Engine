#include "Transform.h"

Transform::Transform(Point point, float rotate, GameObject * object) : Component(object)
{
	this->tag = "Transform";
	this->worldPos = point;
	this->rotation = rotate;
}

Point Transform::GetWorldPos()
{
	return this->worldPos;
}
float Transform::GetRotation()
{
	return this->rotation;
}

void Transform::UpdateRotation(float degrees)
{
	//modulous works with ints
	int intRotation = (int)(degrees + this->rotation);//get the whole number value to modulate
	float decimalDegrees = this->rotation + degrees - intRotation;//calculate the decimal value remaining
	this->rotation = (intRotation % 360) + decimalDegrees;//modulate by 360 (circle) and add the decimal back
}

void Transform::UpdateWorldPos(float x, float y)
{
	this->worldPos.x += x;
	this->worldPos.y += y;
}