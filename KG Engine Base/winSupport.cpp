/*
	___________________________________

	KG Engine Windows/DirectX library
	___________________________________

	Written by Alastair Bilby
	Edited by:

	___________________________________
	
	Description:

	This library works as a wrapper for
	OpenGL and MacOS function calls.
	___________________________________

	Copyright(c) Knoob Group 2013,
	All rights reserved.
	___________________________________
*/

#include "winSupport.h"

#ifdef KG_WIN

#include "keyboard.h"
#include "engine.h"
#include "GraphicsAPI.h"

#include <vector>
#include <algorithm>

#ifndef KG_USEGL
// A list of keys pressed:
std::vector<KG_KeyType> pressedKeys;

// Checks if two values match for working out if a key was released:
KG_KeyType checkAgainst;
bool shouldEmpty(KG_KeyType value) {return (checkAgainst == value);}

bool mL = false;
bool mR = false;
bool mM = false;

// Only use msgProc for DirectX, otherwise we can use GLFW:
LRESULT WINAPI MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	// Windows message listener, from here we get things like key presses:
	switch (msg)
	{
	case WM_KEYDOWN:
		kg::keyBoardControl::keyPress((KG_KeyType)(wParam));
		pressedKeys.push_back((KG_KeyType)(wParam));
		return 0;
	case WM_KEYUP:
		kg::keyBoardControl::keyRelease((KG_KeyType)(wParam));
		checkAgainst = (KG_KeyType)(wParam);
		pressedKeys.erase(pressedKeys.begin(), std::remove_if(pressedKeys.begin(), pressedKeys.end(), shouldEmpty));
		return 0;
	case WM_LBUTTONDOWN:
		kg::keyBoardControl::mouseLPress();
		mL = true;
		return 0;
	case WM_LBUTTONUP:
		kg::keyBoardControl::mouseLRelease();
		mL = false;
		return 0;
	case WM_RBUTTONDOWN:
		kg::keyBoardControl::mouseRPress();
		mR = true;
		return 0;
	case WM_RBUTTONUP:
		kg::keyBoardControl::mouseRRelease();
		mR = false;
		return 0;
	case WM_MBUTTONDOWN:
		kg::keyBoardControl::mouseMPress();
		mM = true;
		return 0;
	case WM_MBUTTONUP:
		kg::keyBoardControl::mouseMRelease();
		mM = false;
		return 0;
	}

	// If 0 did not get returned, make sure we get all messages:
	return DefWindowProc(hWnd, msg, wParam, lParam);
}
#endif

INT WINAPI wWinMain(HINSTANCE hInst, HINSTANCE, LPWSTR, INT)
{
	// Main method for Windows machines:
	// Run starting funtion:
	kg::init();

	kg::initAPI();

	// Set esc key defualt to be quit:
	kg::keyBoardControl::setKeyPress(KGkey_esc, kg::Engine::quit);

	// Etner main loop:
	while (kg::Engine::looping)
	{
		#ifndef KG_USEGL
		// Update pressed keys:
		for (unsigned int i = 0; i < pressedKeys.size(); ++i)
			kg::keyBoardControl::keyPressed(pressedKeys[i]);
		
		// Update mouse buttons pressed:
		if (mL)
			kg::keyBoardControl::mouseLPressed();

		if (mR)
			kg::keyBoardControl::mouseRPressed();

		if (mM)
			kg::keyBoardControl::mouseMPressed();

		#else

		#endif

		// Run Update function:
		kg::updateAPI();
		kg::Engine::lowLevelUpdate();
		kg::update();

		// Run render function:
		kg::openRenderPipeAPI();
		kg::render();
		kg::closeRenderPipeAPI();
	}

	kg::onExit();

	kg::closeAPI();

	return 0;
}

#endif