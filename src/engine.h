/* KGE engine.h
*
* This is simply a engine file to show off how it's done.
* Feel free to copy it then change it as required!
* For instance, don't keep this description, and replace the word engine
* with the name of your header.
*
* Knoob Group Engine 2015,
* all rights reserved.
*/

#ifndef engine_h
#define engine_h
#pragma once

#include "kgBool.h"

/* C compatible code: */
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
	typedef struct engine_
	{
		bool looping;
	} engine;

	extern engine kgEngine;

	void kgBegin(int argc, char **argv);
	void kgEnd(void);

#ifdef __cplusplus
}

/* C++ only code, for instance operator overloading: */

#endif /* __cplusplus */
#endif /* engine_h */
