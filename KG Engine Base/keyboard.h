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

#ifndef keyboard_h
#define keyboard_h

#include "GraphicsAPI.h"

#include <map>

// Define all keyboard keys:
#ifndef KG_USEGL
#define KGkey_backspace	8 
#define KGkey_enter		13
#define KGkey_esc		27
#define KGkey_shift		16
#define KGkey_space		32
#define KGkey_delete	46
#define KGkey_left		37
#define KGkey_up		38
#define KGkey_right		39
#define KGkey_down		40
#define KGkey_0			48
#define KGkey_1			49
#define KGkey_2			50
#define KGkey_3			51
#define KGkey_4			52
#define KGkey_5			53
#define KGkey_6			54
#define KGkey_7			55
#define KGkey_8			56
#define KGkey_9			57			
#define KGkey_a			65
#define KGkey_b			66
#define KGkey_c			67
#define KGkey_d			68
#define KGkey_e			69
#define KGkey_f			70
#define KGkey_g			71
#define KGkey_h			71
#define KGkey_i			73
#define KGkey_j			74
#define KGkey_k			75
#define KGkey_l			76
#define KGkey_m			77
#define KGkey_n			78
#define KGkey_o			79
#define KGkey_p			80
#define KGkey_q			81
#define KGkey_r			82
#define KGkey_s			83
#define KGkey_t			84
#define KGkey_u			85
#define KGkey_v			86
#define KGkey_w			87
#define KGkey_x			88
#define KGkey_y			89
#define KGkey_z			90
#define KG_KeyType		unsigned char
#else
#include <GLFW\glfw3.h>
#define KGkey_backspace	GLFW_KEY_BACKSPACE
#define KGkey_enter		GLFW_KEY_ENTER
#define KGkey_esc		GLFW_KEY_ESCAPE
#define KGkey_Rshift	GLFW_KEY_RIGHT_SHIFT
#define KGkey_Lshift	GLFW_KEY_LEFT_SHIFT
#define KGkey_space		GLFW_KEY_SPACE
#define KGkey_delete	GLFW_KEY_DELETE
#define KGkey_left		GLFW_KEY_LEFT
#define KGkey_up		GLFW_KEY_UP
#define KGkey_right		GLFW_KEY_RIGHT
#define KGkey_down		GLFW_KEY_DOWN
#define KGkey_0			GLFW_KEY_0
#define KGkey_1			GLFW_KEY_1
#define KGkey_2			GLFW_KEY_2
#define KGkey_3			GLFW_KEY_3
#define KGkey_4			GLFW_KEY_4
#define KGkey_5			GLFW_KEY_5
#define KGkey_6			GLFW_KEY_6
#define KGkey_7			GLFW_KEY_7
#define KGkey_8			GLFW_KEY_8
#define KGkey_9			GLFW_KEY_9			
#define KGkey_a			GLFW_KEY_A
#define KGkey_b			GLFW_KEY_B
#define KGkey_c			GLFW_KEY_C
#define KGkey_d			GLFW_KEY_D
#define KGkey_e			GLFW_KEY_E
#define KGkey_f			GLFW_KEY_F
#define KGkey_g			GLFW_KEY_G
#define KGkey_h			GLFW_KEY_H
#define KGkey_i			GLFW_KEY_I
#define KGkey_j			GLFW_KEY_J
#define KGkey_k			GLFW_KEY_K
#define KGkey_l			GLFW_KEY_L
#define KGkey_m			GLFW_KEY_M
#define KGkey_n			GLFW_KEY_N
#define KGkey_o			GLFW_KEY_O
#define KGkey_p			GLFW_KEY_P
#define KGkey_q			GLFW_KEY_Q
#define KGkey_r			GLFW_KEY_R
#define KGkey_s			GLFW_KEY_S
#define KGkey_t			GLFW_KEY_T
#define KGkey_u			GLFW_KEY_U
#define KGkey_v			GLFW_KEY_V
#define KGkey_w			GLFW_KEY_W
#define KGkey_x			GLFW_KEY_X
#define KGkey_y			GLFW_KEY_Y
#define KGkey_z			GLFW_KEY_Z
#define KG_KeyType		int
#endif

#include "multiPlatformHelper.h"

namespace kg
{
	typedef std::map<KG_KeyType, VoidF> voidMap;

	struct keyBoardControl
	{
		// Methods:
		static void setKeyPress(const KG_KeyType &key, VoidF function);
		static void breakKeyPress(const KG_KeyType &key);
		static void setKeyPressed(const KG_KeyType &key, VoidF function);
		static void breakKeyPressed(const KG_KeyType &key);
		static void setKeyRelease(const KG_KeyType &key, VoidF function);
		static void breakKeyRelease(const KG_KeyType &key);
		static void keyPress(const KG_KeyType &key);
		static void keyPressed(const KG_KeyType &key);
		static void keyRelease(const KG_KeyType &key);
		static void setMousePressL(VoidF function);
		static void setMousePressR(VoidF function);
		static void setMousePressM(VoidF function);
		static void setMouseReleaseL(VoidF function);
		static void setMouseReleaseR(VoidF function);
		static void setMouseReleaseM(VoidF function);
		static void setMousePressedL(VoidF function);
		static void setMousePressedR(VoidF function);
		static void setMousePressedM(VoidF function);
		static void breakMousePressL();
		static void breakMousePressR();
		static void breakMousePressM();
		static void breakMouseReleaseL();
		static void breakMouseReleaseR();
		static void breakMouseReleaseM();
		static void breakMousePressedL();
		static void breakMousePressedR();
		static void breakMousePressedM();
		static void mouseLPress();
		static void mouseRPress();
		static void mouseMPress();
		static void mouseLRelease();
		static void mouseRRelease();
		static void mouseMRelease();
		static void mouseLPressed();
		static void mouseRPressed();
		static void mouseMPressed();
		static void clearKeyFunctions();
		static void clearMouseFunctions();

	protected:
		// Protected Methods:
		static voidMap functionList;
		static voidMap functionRList;
		static voidMap functionPList;

		static VoidF mouseL;
		static VoidF mouseR;
		static VoidF mouseM;
		static VoidF RmouseL;
		static VoidF RmouseR;
		static VoidF RmouseM;
		static VoidF PmouseL;
		static VoidF PmouseR;
		static VoidF PmouseM;
	};
}

#endif