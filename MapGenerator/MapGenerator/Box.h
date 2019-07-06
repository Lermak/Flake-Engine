#ifndef Box_Class
#define Box_Class
#include "Point.h"
#include "Component.h"
#include "GameObject.h"
#include "Transform.h"

class Box : public Component
{
public:
	float verticies[36];
	unsigned int VBO, VAO, EBO;
	Transform * myTransform;
	float width;
	float height;
	unsigned int texture;
	Box(float width, float height, Transform * myTrans, GameObject * object);
	void GetVerticies(float screenWidth, float screenHeight);
	Point TopLeft();
	Point TopRight();
	Point BottomLeft();
	Point BottomRight();
	static const unsigned int indices[36];
private:	
	Point getRotatedPos(float degrees);
	int shaderProgram;	
protected:
};
#endif

