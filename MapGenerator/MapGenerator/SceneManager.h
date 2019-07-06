#ifndef SceneManager_Class
#define SceneManager_Class

#include "GameObject.h"
#include "Scene.h"

class SceneManager
{
public:
	Scene currentScene;
	void LoadScene(const char * sceneID);
private:
protected:
};
#endif

