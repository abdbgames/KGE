/* KGE openGLAPI.c
*
* This is a simple header to define openGL specifics.
*
* Knoob Group Engine 2015,
* all rights reserved.
*/

#ifndef openGLAPI_h
#define openGLAPI_h
#pragma once

#include "dependencies.h"

#include <GL/glew.h>
#include <SDL/SDL_openGL.h>

/* C compatible code: */
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

	void kgInitGL(void)
	{
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
			SDL_GL_CONTEXT_PROFILE_CORE);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

		// Specify prototype of function:
		typedef void(*GENBUFFERS) (GLsizei, GLuint*);

		// Load address of function and assign it to a function pointer:
#		ifdef _WIN32
		GENBUFFERS glGenBuffers = 
			(GENBUFFERS)wglGetProcAddress("glGenBuffers");
#		elif __APPLE__
		GENBUFFERS glGenBuffers = 
			(GENBUFFERS)glXGetProcAddress((const GLubyte *) "glGenBuffers");
#		else /* __APPLE__ */
		GENBUFFERS glGenBuffers = 
			(GENBUFFERS)NSGLGetProcAddress("glGenBuffers");
#		endif /* _WIN32 */

		// Call function as normal:
		GLuint buffer;
		glGenBuffers(1, &buffer);
	}

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* openGLAPI_h */
