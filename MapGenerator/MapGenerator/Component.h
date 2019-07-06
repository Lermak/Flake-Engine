#ifndef Component_Class
#define Component_Class
class GameObject;

class Component
{
public:
	GameObject * MyObject;
	Component(GameObject * object);
	const char * tag;
	virtual void Run();
protected:
private:
};

#endif