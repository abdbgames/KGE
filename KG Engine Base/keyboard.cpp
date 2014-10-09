/*
	___________________________________

	KG Engine Keyboard library
	___________________________________

	Written by Alastair Bilby
	Edited by:

	___________________________________
	
	Description:

	This library handles user input.
	It allows the user to effectivly
	attach a function call they have
	declared and defined to a key, and
	whenether that key is detected it
	runs the assosiated function.
	___________________________________

	Copyright(c) Knoob Group 2013,
	All rights reserved.
	___________________________________
*/

#include "keyboard.h"

namespace kg
{
	voidMap keyBoardControl::functionList;
	voidMap keyBoardControl::functionRList;
	voidMap keyBoardControl::functionPList;
	VoidF keyBoardControl::mouseL = NULL;
	VoidF keyBoardControl::mouseR = NULL;
	VoidF keyBoardControl::mouseM = NULL;
	VoidF keyBoardControl::RmouseL = NULL;
	VoidF keyBoardControl::RmouseR = NULL;
	VoidF keyBoardControl::RmouseM = NULL;
	VoidF keyBoardControl::PmouseL = NULL;
	VoidF keyBoardControl::PmouseR = NULL;
	VoidF keyBoardControl::PmouseM = NULL;

	void keyBoardControl::setKeyPress(const KG_KeyType &key, VoidF function)
	{
		// Add a pointer to a function, and assign it to a keyboard press:
		functionPList[key] = function;
	}

	void keyBoardControl::breakKeyPress(const KG_KeyType &key)
	{
		// If the assignment exists:
		if (functionPList.find(key) != functionPList.end())
		{
			if (functionPList[key] != NULL)
				// Get rid of the assignment:
				functionPList[key] = NULL;
		}
	}

	void keyBoardControl::setKeyPressed(const KG_KeyType &key, VoidF function)
	{
		// Add a pointer to a function, and assign it to a keyboard press:
		functionList[key] = function;
	}

	void keyBoardControl::breakKeyPressed(const KG_KeyType &key)
	{
		// If the assignment exists:
		if (functionList.find(key) != functionList.end())
		{
			if (functionList[key] != NULL)
				// Get rid of the assignment:
				functionList[key] = NULL;
		}
	}

	void keyBoardControl::keyPress(const KG_KeyType &key)
	{
		// If the assignment exists:
		if (functionPList.find(key) != functionPList.end())
		{
			if (functionPList[key] != NULL)
				// Run the assigned function:
				functionPList[key]();
		}
	}

	void keyBoardControl::keyPressed(const KG_KeyType &key)
	{
		// If the assignment exists:
		if (functionList.find(key) != functionList.end())
		{
			if (functionList[key] != NULL)
				// Run the assigned function:
				functionList[key]();
		}
	}

	void keyBoardControl::setKeyRelease(const KG_KeyType &key, VoidF function)
	{
		// Add a pointer to a function, and assign it to a keyboard press:
		functionRList[key] = function;
	}

	void keyBoardControl::breakKeyRelease(const KG_KeyType &key)
	{
		// If the assignment exists:
		if (functionRList.find(key) != functionRList.end())
		{
			if (functionRList[key] != NULL)
			{
				// Get rid of the assignment:
				functionRList[key] = NULL;
				functionRList.erase(functionRList.find(key));
			}
		}
	}

	void keyBoardControl::keyRelease(const KG_KeyType &key)
	{
		// If the assignment exists:
		if (functionRList.find(key) != functionRList.end())
		{
			if (functionRList[key] != NULL)
				// Run the assigned function:
				functionRList[key]();
		}
	}

	void keyBoardControl::clearKeyFunctions()
	{
		// Clear the lists:
		functionRList.clear();
		functionPList.clear();
		functionList.clear();
	}

	void keyBoardControl::clearMouseFunctions()
	{
		// Set all to NULL:
		mouseL = NULL;
		mouseR = NULL;
		mouseM = NULL;
		RmouseL = NULL;
		RmouseR = NULL;
		RmouseM = NULL;
		PmouseL = NULL;
		PmouseR = NULL;
		PmouseM = NULL;
	}

	void keyBoardControl::setMousePressL(VoidF function)
	{
		mouseL = function;
	}

	void keyBoardControl::setMousePressR(VoidF function)
	{
		mouseR = function;
	}

	void keyBoardControl::setMousePressM(VoidF function)
	{
		mouseM = function;
	}

	void keyBoardControl::setMouseReleaseL(VoidF function)
	{
		RmouseL = function;
	}

	void keyBoardControl::setMouseReleaseR(VoidF function)
	{
		RmouseR = function;
	}

	void keyBoardControl::setMouseReleaseM(VoidF function)
	{
		RmouseM = function;
	}

	void keyBoardControl::setMousePressedL(VoidF function)
	{
		PmouseL = function;
	}

	void keyBoardControl::setMousePressedR(VoidF function)
	{
		PmouseR = function;
	}

	void keyBoardControl::setMousePressedM(VoidF function)
	{
		PmouseM = function;
	}

	void keyBoardControl::breakMousePressL()
	{					  
		mouseL = NULL;
	}					  
						  
	void keyBoardControl::breakMousePressR()
	{					  
		mouseR = NULL;
	}					  
						  
	void keyBoardControl::breakMousePressM()
	{					  
		mouseM = NULL;
	}					  
						  
	void keyBoardControl::breakMouseReleaseL()
	{					  
		RmouseL = NULL;
	}					  
						  
	void keyBoardControl::breakMouseReleaseR()
	{					  
		RmouseR = NULL;
	}					  
						  
	void keyBoardControl::breakMouseReleaseM()
	{					 
		RmouseM = NULL;
	}					 
						 
	void keyBoardControl::breakMousePressedL()
	{					  
		PmouseL = NULL;
	}					  
						  
	void keyBoardControl::breakMousePressedR()
	{					 
		PmouseR = NULL;
	}					 
						 
	void keyBoardControl::breakMousePressedM()
	{
		PmouseM = NULL;
	}
	
	void keyBoardControl::mouseLPress()
	{
		if (mouseL != NULL)
			mouseL();
	}

	void keyBoardControl::mouseRPress()
	{
		if (mouseR != NULL)
			mouseR();
	}

	void keyBoardControl::mouseMPress()
	{
		if (mouseM != NULL)
			mouseM();
	}

	void keyBoardControl::mouseLRelease()
	{
		if (RmouseL != NULL)
			RmouseL();
	}

	void keyBoardControl::mouseRRelease()
	{
		if (RmouseR != NULL)
			RmouseR();
	}

	void keyBoardControl::mouseMRelease()
	{
		if (RmouseM != NULL)
			RmouseM();
	}

	void keyBoardControl::mouseLPressed()
	{
		if (PmouseL != NULL)
			PmouseL();
	}

	void keyBoardControl::mouseRPressed()
	{
		if (PmouseR != NULL)
			PmouseR();
	}

	void keyBoardControl::mouseMPressed()
	{
		if (PmouseM != NULL)
			PmouseM();
	}
}