#include <glad/glad.h>
#include <GLFW/glfw3.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include "Box.h"
#include "SpriteRenderer.h"
#include "Component.h"
#include "GameObject.h"
#include "BehaviorHandler.h"
#include "Behavior.h"
#include "WASDControlls.h"
#include "CollisionHandler.h"
#include "CollisionManager.h"
//declare static behaviors
static WASDControlls wasdControlls;

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

/**********************************************************/
//Create GameObjects
GameObject player;

//Create Components
Transform playerTransform(Point(50,50), 0.0f, &player);
Box myBox(40.0f, 40.0f, &playerTransform, &player);
SpriteRenderer myRenderer(&myBox, "test.jpg", &player);
Behavior * playerBehaviors[1] = {
	&wasdControlls
};

BehaviorHandler playerBH(playerBehaviors, 1, &player);
CollisionHandler playerCH(playerCollisions, 1, &player);

//Create Component Arrays
Component * playerComp[4] = {
	&playerBH,
	&playerTransform,
	&myBox,
	&myRenderer
};

/***********************************************************/
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

const char *vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
const char *fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(.5f, .5f, .5f, .5f);\n"
"}\n\0";

int main()
{
	//Link Component Arrays to GameObjects
	player.SetComponents(playerComp, 4);

	// glfw: initialize and configure
	// ------------------------------
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
#endif

	// glfw window creation
	// --------------------
	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// glad: load all OpenGL function pointers
	// ---------------------------------------
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
	SpriteRenderer * renderer = ((SpriteRenderer *)(player.GetComponent("SpriteRenderer")));
	renderer->SetupImage();
	renderer->SetupShaders();
	renderer->Bind(SCR_WIDTH, SCR_HEIGHT);


	// render loop
	// -----------
	while (!glfwWindowShouldClose(window))
	{
		// input
		// -----
		processInput(window);

		// render
		// ------
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		((SpriteRenderer *)(player.GetComponent("SpriteRenderer")))->Draw();
		
		((BehaviorHandler *)(player.GetComponent("BehaviorHandler")))->RunBehaviors();

		((SpriteRenderer *)(player.GetComponent("SpriteRenderer")))->Bind(SCR_WIDTH, SCR_HEIGHT);
		
		// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
		// -------------------------------------------------------------------------------
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// glfw: terminate, clearing all previously allocated GLFW resources.
	// ------------------------------------------------------------------
	glfwTerminate();
	return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}