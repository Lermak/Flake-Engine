#include <math.h>
#include "glad.h"
#include <GLFW/glfw3.h>
#include "Box.h"
#include <iostream>
#include "stb_image.h"

const unsigned int Box::indices[] = { 0, 1, 3, 1, 2, 3 };

Box::Box(float width, float height, Transform * myTrans, GameObject * object) : Component(object)
{
	this->tag = "Box";
	this->myTransform = myTrans;
	this->width = width;
	this->height = height;


	//top right
	verticies[2] = 0;//z position
	verticies[3] = 1.0f; // colors
	verticies[4] = 0.0f;
	verticies[5] = 0.0f;
	verticies[6] = 1.0f; // texture coords
	verticies[7] = 1.0f;

	//bottom right
	verticies[10] = 0;
	verticies[11] = 0.0f;
	verticies[12] = 1.0f;
	verticies[13] = 0.0f;
	verticies[14] = 1.0f;
	verticies[15] = 0.0f;

	//bottom left
	verticies[18] = 0;
	verticies[19] = 0.0f;
	verticies[20] = 0.0f;
	verticies[21] = 1.0f;
	verticies[22] = 0.0f;
	verticies[23] = 0.0f;

	//top left
	verticies[26] = 0;
	verticies[27] = 1.0f;
	verticies[28] = 1.0f;
	verticies[29] = 0.0f;
	verticies[30] = 0.0f;
	verticies[31] = 1.0f;

}

Point Box::getRotatedPos(float degrees)
{
	float a = (degrees) * (3.14159f / 180);
	Point p;
	p.x = cos(a) * (width / 2) - sin(a) * (height / 2) + this->myTransform->GetWorldPos().x;
	p.y = sin(a) * (width / 2) + cos(a) * (height / 2) + this->myTransform->GetWorldPos().y;
	return p;
}

Point Box::TopLeft()
{
	return getRotatedPos(this->myTransform->GetRotation() + 90);
}
Point Box::TopRight()
{
	return getRotatedPos(this->myTransform->GetRotation());
}
Point Box::BottomLeft()
{
	return getRotatedPos(this->myTransform->GetRotation() + 180);
}
Point Box::BottomRight()
{
	return getRotatedPos(this->myTransform->GetRotation() + 270);
}

void Box::GetVerticies(float screenWidth, float screenHeight)
{																									          
	verticies[0] = TopRight().x / (screenWidth / 2) - 1; 
	verticies[1] = TopRight().y / (screenHeight / 2) - 1;
	
	verticies[8] = BottomRight().x / (screenWidth / 2) - 1;
	verticies[9] = BottomRight().y / (screenHeight / 2) - 1;
	

	verticies[16] = BottomLeft().x / (screenWidth / 2) - 1;
	verticies[17] = BottomLeft().y / (screenHeight / 2) - 1;

	verticies[24] = TopLeft().x / (screenWidth / 2) - 1;
	verticies[25] = TopLeft().y / (screenHeight / 2) - 1;
}