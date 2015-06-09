/* KGE kgBool.h
*
* kgBool.h gives C++ style booleans when using C.
*
* Knoob Group Engine 2015,
* all rights reserved.
*/

#ifndef kgBool_h
#define kgBool_h
#pragma once
#ifndef __cplusplus

/* define bool, true and false: */
#define bool char
#define true 1
#define false 0

/* prevent stdbool.h from redefining: */
#define __bool_true_false_are_defined 1

#endif /* __cplusplus */
#endif /* kgBool_h */
