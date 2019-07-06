#ifndef WASDControlls_Class
#define WASDControlls_Class
#include <Windows.h>
#include "Behavior.h"
#include "Component.h"
#include "Transform.h"

class WASDControlls : public Behavior
{
public:
	virtual void RunBehavior(GameObject * object) override;
private:

protected:
};
#endif

