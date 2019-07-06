#ifndef GameObject_Class
#define GameObject_Class

class Component;

class GameObject
{
public:	
	void Run();
	GameObject();
	Component * GetComponent(const char * tag);
	void SetComponents(Component * c[], int num);
protected:
private:
	Component ** components;
	int numComponents;
};
#endif