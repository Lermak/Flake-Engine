#include "Component.h"
#include "GameObject.h"

Component::Component(GameObject * object)
{
	this->MyObject = object;
}

void Component::Run()
{

}