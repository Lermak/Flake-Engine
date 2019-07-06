#include "WASDControlls.h"

void WASDControlls::RunBehavior(GameObject * object)
{
	Transform * myTransform = (Transform *)(object->GetComponent("Transform"));

	if (GetAsyncKeyState('Q') & 0x8000)
	{
		myTransform->UpdateRotation(.125f);
	}
	else if (GetAsyncKeyState('E') & 0x8000)
	{
		myTransform->UpdateRotation(-0.125f);
	}

	if (GetAsyncKeyState('W') & 0x8000)
	{
		myTransform->UpdateWorldPos(0, 1);
	}
	else if (GetAsyncKeyState('A') & 0x8000)
	{
		myTransform->UpdateWorldPos(-1, 0);
	}
	else if (GetAsyncKeyState('S') & 0x8000)
	{
		myTransform->UpdateWorldPos(0, -1);
	}
	else if (GetAsyncKeyState('D') & 0x8000)
	{
		myTransform->UpdateWorldPos(1, 0);
	}
}