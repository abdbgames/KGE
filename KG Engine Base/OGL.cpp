/*
	___________________________________

	KG Engine OpenGL support library
	___________________________________

	Written by Alastair Bilby
	Edited by:
	Zak Stephens

	___________________________________
	
	Description:

	This library is designed to act out
	all KG Engine commands to the GPU
	via OpenGL.
	___________________________________

	Copyright(c) Knoob Group 2013,
	All rights reserved.
	___________________________________
*/

#include "GraphicsAPI.h"

#ifdef KG_USEGL

#define GLEW_STATIC 1

#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include "keyboard.h"
#include "loadShadersOGL.h"
#include "engine.h"

#include <vector>
#include <algorithm>

// Window pointer:
GLFWwindow *KG_MAINWINDOW;

// Monitor pointer:
GLFWmonitor *KG_MONITOR;

// Shader Index:
GLuint programID;

// Camera transform to be sent to GPU:
GLuint matrixID;

// Identity Matrix16, just in case:
kg::Matrix16 matrixIdentity;

// A list of keys pressed:
std::vector<int> pressedKeys;

// Checks if two values match for working out if a key was released:
KG_KeyType checkAgainst;
bool shouldEmpty(KG_KeyType value) {return (checkAgainst == value);}

bool mL = false;
bool mR = false;
bool mM = false;

namespace kg
{
	static void KGkeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		// Handles the key input machine:
		switch (action)
		{
		case GLFW_PRESS:
			kg::keyBoardControl::keyPress(key);
			pressedKeys.push_back(key);
			break;
		case GLFW_RELEASE:
			kg::keyBoardControl::keyRelease(key);
			checkAgainst = (key);
			pressedKeys.erase(pressedKeys.begin(), std::remove_if(pressedKeys.begin(), pressedKeys.end(), shouldEmpty));
			break;
		}
		
	}

	static void KGMouseCallback(GLFWwindow* window, int button, int action, int mods)
	{
		// Handles the mouse button machine:
		switch (button)
		{
		case GLFW_MOUSE_BUTTON_LEFT:
			if (action == GLFW_PRESS)
			{
				kg::keyBoardControl::mouseLPress();
				mL = true;
				break;
			}

			if (action == GLFW_RELEASE)
			{
				kg::keyBoardControl::mouseLRelease();
				mL = false;
				break;
			}
		case GLFW_MOUSE_BUTTON_MIDDLE:
			if (action == GLFW_PRESS)
			{
				kg::keyBoardControl::mouseMPress();
				mM = true;
				break;
			}

			if (action == GLFW_RELEASE)
			{
				kg::keyBoardControl::mouseMRelease();
				mM = false;
				break;
			}
		case GLFW_MOUSE_BUTTON_RIGHT:
			if (action == GLFW_PRESS)
			{
				kg::keyBoardControl::mouseRPress();
				mR = true;
				break;
			}

			if (action == GLFW_RELEASE)
			{
				kg::keyBoardControl::mouseRRelease();
				mR = false;
				break;
			}
		}
	}

	static const GLfloat g_vertex_buffer_data[] = {
						   -1.0f, -1.0f, 0.0f,
						   1.0f, -1.0f, 0.0f,
						   0.0f,  1.0f, 0.0f,
						};

	// This will identify our vertex buffer
	GLuint vertexbuffer;

	void initAPI()
	{
		// Initialises GLFW:
		glfwInit();

		// We want OpenGL 4.2, it's supported by most things out there :P
		// For unsupported cards, we will add DirectX later, and perhaps a legacy version
		// of OpenGL, and even look into Mantle!
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);

		// Pick a window to use:
		KG_MONITOR = (Engine::currentMonitor == 1) ? glfwGetPrimaryMonitor() : NULL;

		// Creates a generic window in fullscreen mode:
		KG_MAINWINDOW = glfwCreateWindow(1280, 720, "Knoob Group Engine Alpha Environment", KG_MONITOR, NULL);

		// Forces OpenGL to grab our window:
		glfwMakeContextCurrent(KG_MAINWINDOW);

		// Initialises GLEW:
		glewInit();

		// Makes OpenGL use our input listeners:
		glfwSetKeyCallback(KG_MAINWINDOW, KGkeyCallback);
		glfwSetMouseButtonCallback(KG_MAINWINDOW, KGMouseCallback);

		// Loads in Shaders:
		programID = loadShaders("BasicVertex.glsl", "BasicFragment.glsl");

		// Set up camera Matrix:
		matrixID = glGetUniformLocation(programID, "MVP");
 
		// Generate 1 buffer, put the resulting identifier in vertexbuffer
		glGenBuffers(1, &vertexbuffer);
 
		// The following commands will talk about our 'vertexbuffer' buffer
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
 
		// Give our vertices to OpenGL.
		glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
	}

	void closeAPI()
	{
		// Destroys the Window:
		glfwDestroyWindow(KG_MAINWINDOW);

		// Terminates OpenGL and helpers:
		glfwTerminate();
	}

	void updateAPI()
	{
		// Update pressed keys:
		for (unsigned int i = 0; i < pressedKeys.size(); ++i)
			keyBoardControl::keyPressed(pressedKeys[i]);
		
		// Update mouse buttons pressed:
		if (mL)
			keyBoardControl::mouseLPressed();

		if (mR)
			keyBoardControl::mouseRPressed();

		if (mM)
			keyBoardControl::mouseMPressed();
	}

	void openRenderPipeAPI()
	{
		// Called before render:
		int width, height;
		glfwGetFramebufferSize(KG_MAINWINDOW, &width, &height);
		glViewport(0, 0, width, height);
		glClearColor(1.0f, 1.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(programID);

		// Set up camera context:
		(Engine::currentCamera != NULL) ?
		glUniformMatrix4fv(matrixID, 1, GL_FALSE, Engine::currentCamera->getMat()->getMatGL()) :
		glUniformMatrix4fv(matrixID, 1, GL_FALSE, matrixIdentity.getMatGL());

		// 1rst attribute buffer : vertices
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		glVertexAttribPointer(
		   0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		   3,                  // size
		   GL_FLOAT,           // type
		   GL_FALSE,           // normalized?
		   0,                  // stride
		   (void*)0            // array buffer offset
		);
 
		// Draw the triangle !
		glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
 
		glDisableVertexAttribArray(0);
	}

	void closeRenderPipeAPI()
	{
		// Called after render:
		glfwSwapBuffers(KG_MAINWINDOW);
		glfwPollEvents();
	}

	int callbackShouldClose()
	{
		// Checks if the user has entered ALT-F4, hit the close button etc:
		return glfwWindowShouldClose(KG_MAINWINDOW);
	}
}

#endif