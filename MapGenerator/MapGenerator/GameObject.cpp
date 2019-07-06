#include "GameObject.h"
#include "Component.h"

GameObject::GameObject()
{

}

void GameObject::SetComponents(Component * c[], int num)
{
	this->components = c;
	this->numComponents = num;
}

void GameObject::Run()
{
	for (int i = 0; i < numComponents; ++i)
	{
		(*(components[i])).Run();
	}
}

Component * GameObject::GetComponent(const char * tag)
{
	for (int i = 0; i < numComponents; ++i)
	{
		if ((*(components[i])).tag == tag)
		{
			return &(*(components[i]));
		}
	}
	throw "Object can not be found.";//if no component is found with that tag, throw exception
}
