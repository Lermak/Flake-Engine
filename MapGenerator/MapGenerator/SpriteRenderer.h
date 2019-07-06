#ifndef SpriteRenderer_Class
#define SpriteRenderer_Class

#include "Component.h"
#include "Box.h"
#include "GameObject.h"

class SpriteRenderer : public Component
{
public:
	const char* imgFile;
	SpriteRenderer(Box * drawBox, const char * imgFile, GameObject * object);
	void Draw();
	void SetupShaders();
	void SetupImage();
	void Bind(float screenWidth, float screenHeight);
private:
	unsigned int texture;
	Box* DrawBox;
	int shaderProgram;
	unsigned int VAO, VBO, EBO;
protected:
};
#endif