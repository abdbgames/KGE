/* KGE dependencies.h
 *
 * Includes all platform specific dependencies based on target system.
 *
 * Knoob Group Engine 2015,
 * all rights reserved.
 */

#ifndef dependencies_h
#define dependencies_h
#pragma once

/* Global dependencies: */
#include <SDL/SDL.h>

#if _WIN32
/* Windows specific dependencies: */
#elif /* _WIN32 */
/* Non Windows specific dependencies: */
#	ifndef _OGL
#	define _OGL
#	endif /* _OGL */
#endif /* _WIN32 */

#ifdef _OGL
	/* OpenGL specific dependencies:
	*
	* On Linux or MacOS:
	* openGL will be automatically used as the default.
	*
	* With Cygwin:
	* For this you will need to add CFLAGS+=-D_OGL to your makefile.
	*
	* With Visual Studio:
	* you will need to make sure you have _OGL as a preprocessor definition.
	* ("properties\C/C++\Preprocessor\Preprocessor definitions")
	*/
#	ifndef _OGL_VERSION_MAJOR
#	define _OGL_VERSION_MAJOR 3
#	endif /* _OGL_VERSION_MAJOR */
#	ifndef _OGL_VERSION_MINOR
#	define _OGL_VERSION_MINOR 2
#	endif /* _OGL_VERSION_MINOR */
#else /* _OGL */
	/* DirectX specific dependencies:
	*
	* On Linux or MacOS:
	* This cannot be used.
	*
	* With Cygwin:
	* For this you will need to remove -D_OGL from your makefile if it exists.
	*
	* With Visual Studio:
	* you will need to make sure you do not have _OGL as a preprocessor
	* definition.
	* ("properties\C/C++\Preprocessor\Preprocessor definitions")
	*/
#	ifndef _DX_VERSION
#	define _DX_VERSION 9
#	endif /* _DX_VERSION */
#endif /* _OGL */

/* Internal functions for specific Graphis API's */
void kgInitGL(void);
void kgInitDX(void);

/* Initialise graphics API of choice: */
void kgInitGraphicsAPI(void)
{
#	ifdef _OGL
	kgInitGL();
#	else /* _OGL */
	kgInitDX();
#	endif /* _OGL */
}

#endif /* dependencies_h */
