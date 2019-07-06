#ifndef GameManager_Class
#define GameManager_Class

#include "GameObject.h"

class GameManager
{
public:
	void RenderGameObjects();
	void RunGameObjectBehaviors();
	void GameLoop();
	void PauseGameLoop();
private:
	bool paused;
	GameObject myGameObjects[];
protected:
};
#endif

