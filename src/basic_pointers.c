/*
 * basic_pointers.c
 *
 *  Created on: 04-Apr-2016
 *      Author: MSamal
 *
 *  LICENSE:-
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */




/*
 *----------------------------------------------------------------------
 *   Include Files
 *----------------------------------------------------------------------
 */
#include <stdio.h>

/*
*----------------------------------------------------------------------
*   Private Defines
*----------------------------------------------------------------------
*/

/*
*----------------------------------------------------------------------
*   Private Macros
*----------------------------------------------------------------------
*/


/*
*----------------------------------------------------------------------
*   Private Data Types
*----------------------------------------------------------------------
*/


/*
*----------------------------------------------------------------------
*   Public Variables
*----------------------------------------------------------------------
*/


/*
*----------------------------------------------------------------------
*   Private Variables (static)
*----------------------------------------------------------------------
*/

/*
*----------------------------------------------------------------------
*   Public Constants
*----------------------------------------------------------------------
*/

/*
*----------------------------------------------------------------------
*   Private Constants (static)
*----------------------------------------------------------------------
*/

/*
*----------------------------------------------------------------------
*   Private Function Prototypes (static)
*----------------------------------------------------------------------
*/
static void GetIntFromPtr(int *some_ptr);
static void GetIntFromVar(int some_var);
static void ModifyIntByUsingReference(int *some_ptr);
static void ModifyIntByUsingValue(int some_value);

/*
*----------------------------------------------------------------------
*   Private Functions Definitions
*----------------------------------------------------------------------
*/

/* Passing an integer to a function "by-value" */
static void GetIntFromVar(int some_var)
{
	printf("\n%s(%d)\n", __FUNCTION__,some_var);
	/* The value of the variable passed to this function is
	 * copied into some_var when this function code is executed.
	 * we can get the value passed to this function by accessing
	 * some_var
	 * */
	printf("The value of varA is: %d (passed to function by-value)\n", some_var);
}

/* Passing an integer to a function "by-reference" */
static void GetIntFromPtr(int *some_ptr)
{
	printf("\n%s(%d)\n", __FUNCTION__, (int)some_ptr);
	/* The address of the variable passed to this function is
	 * copied into some_ptr when this function code is executed.
	 *
	 * Since some_ptr now points to the address of the variable,
	 * to get the value of variable, we need to "de-reference" the
	 * pointer some_ptr by using a "*" operator preceding some_ptr
	 *
	 * Note:
	 * Even though the parameter passed to this function is a variable's
	 * address, it is still "some value", which is passed
	 * by-value to this function. For any function call, the
	 * input parameters are ALWAYS passed by-value. How you use the
	 * parameter in the function determines whether it's used by-value
	 * or by-reference inside the function.
	 *
	 * Some of these parameters may be addresses to some variables
	 * like in this case, it is the address of variable varA.
	 *
	 * Since we are passing the address of varA instead of the value
	 * of varA, it is referred to as pass by-reference for varA.
	 *
	 * */
	if (some_ptr != NULL)
	{
		printf("The value of varA is: %d (passed to function by-reference)\n", *some_ptr);
	}
	else
	{
		printf("Null pointer exception\n");
	}
}

/* Passing an integer to a function "by-value"
 * Modifying the value by using the reference */
static void ModifyIntByUsingValue(int some_value)
{
	/* Since the variable's value is passed,
	 * we cannot modify the original variable's
	 * value, but we can modify the value of
	 * its copy which is in some_value
	 * */
	printf("\n%s(%d)\n", __FUNCTION__,some_value);
	printf("The value of varA is: %d (passed to function by-value)\n", some_value);
	some_value = 10;
	printf("The value of varA modified to: %d (Modified by using value)\n", some_value);
}

/* Passing an integer to a function "by-reference"
 * Modifying the value by using the reference */
static void ModifyIntByUsingReference(int *some_ptr)
{
	/* Since the variable's address is passed,
	 * we can use the dereference operator (*) to
	 * access and modify the variable's value
	 * */
	printf("\n%s(%d)\n", __FUNCTION__, (int)some_ptr);
	if (some_ptr != NULL)
	{
		printf("The value of varA is: %d (passed to function by-reference)\n", *some_ptr);
		*some_ptr = 10;
		printf("The value of varA modified to: %d (Modified by using reference)\n", *some_ptr);
	}
	else
	{
		printf("Null pointer exception\n");
	}
}

/*
*----------------------------------------------------------------------
*   Export Functions Definitions
*----------------------------------------------------------------------
*/

void BasicPointers(void)
{
	/* define a integer variable */
	int varA; /* contains junk value because it is not initialized here */

	/* define a pointer to the integer */
	int *ptrA; /* contains junk value because it is not initialized here */

	printf("\n-----------------------\n");
	printf("Basic use of pointers\n");
	printf("-----------------------\n\n");
	/* set some values in the integer variable */
	varA = 5; /* varA now contains 5 */

	/* set the integer pointer to point to the integer variable */
	ptrA = &varA; /* the & operator preceding varA gets the address of varA, ptrA now "points" to varA */

	printf("%s()\n", __FUNCTION__);

	/* get the value of varA directly */
	printf("The value of varA is: %d (reading via varA)\n", varA);

	/* get the address of varA directly */
	printf("The address of varA is: %d\n", (int)&varA);

	/* get the value of varA indirectly through ptrA
	 * since ptrA now points to the address of varA,
	 * to get the value of varA, we need to "de-reference" the
	 * pointer ptrA by using a "*" operator preceding ptrA
	 * */
	printf("The value of varA is: %d (reading via ptrA)\n", *ptrA);

	/* Pass varA by-value */
	GetIntFromVar(varA);

	/* Pass varA by-reference */
	GetIntFromPtr(&varA);

	/* Try to modify value of varA by passing by-value */
	ModifyIntByUsingValue(varA);

	printf("The value of varA after call to ModifyIntByUsingValue(varA): %d\n", varA);

	/* Try to modify value of varA by passing by-reference */
	ModifyIntByUsingReference(&varA);

	printf("The value of varA after call to ModifyIntByUsingReference(&varA): %d\n", varA);

	printf("\n");
	printf("-----------------------\n\n");
}
