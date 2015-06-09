/* KGE engine.h
*
* The KGE engine files are designed to keep track and modify runtime variables,
* these work as global variables that can be accessed from anywhere with
* engine.h included.
*
* Knoob Group Engine 2015,
* all rights reserved.
*/

#include "engine.h"
#include "dependencies.h"

/* C++ only code, for instance operator overloading: */
#ifdef __cplusplus
#	include <cstdio>
#else /* __cplusplus */
#	include <stdio.h>
#endif /* __cplusplus */

/* C compatible code: */
void kgBegin(int argc, char **argv)
{
	// Variable declaration:
	int i;

	// Ititialise engine variables:
	engine kgEngine;

	// Engine default variables:
	kgEngine.looping = true;

	// Attempt to get engine arguments from argv:
	for (i = 1; i < argc; ++i)
	{
		if (argv[i][0] != '-')
		{
			// Expected a flag:
			printf("Unable to determine argument: %s.\n"
				"Expected input flags start with \"-\"", argv[i]);
			continue;
		}
	}

	// Ititialise graphics API:
	kgInitGraphicsAPI();
}

void kgEnd(void)
{
	// Cleanup time:

}
