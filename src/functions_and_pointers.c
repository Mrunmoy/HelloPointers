/*
 * functions_and_pointers.c
 *
 *  Created on: 04-Apr-2016
 *      Author: Mrunmoy Samal
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
int TestFunction(int a, int b);
void ExecuteFunctionPassedbyValue(int (*funcPtr)(int,int));
void ExecuteFunctionPassedbyReference(int (**funcPtr)(int,int));

/*
*----------------------------------------------------------------------
*   Private Functions Definitions
*----------------------------------------------------------------------
*/

/* A Function which takes in two integer parameters
 * and returns their sum.
 * */
int TestFunction(int a, int b)
{
	printf("%s(%d, %d)\n",__FUNCTION__, a, b);
	printf("the sum of %d and %d is %d\n", a, b, (a+b));
	return (a+b);
}

/* Passing poiter to Function by-value */
void ExecuteFunctionPassedbyValue(int (*funcPtr)(int,int))
{
	printf("\n%s(%d)\n",__FUNCTION__, (int)funcPtr);
	/* check if the pointer passed to this function is
	 * not NULL before dereferencing it */
	if (funcPtr != NULL)
	{
		int result ;
		printf("Calling function pointer passed by-value\n");
		result = funcPtr(3, 4);
		printf("result = %d\n", result);
	}
	else
	{
		printf("Null pointer exception\n");
	}
}

/* Passing poiter to Function by-reference */
void ExecuteFunctionPassedbyReference(int (**funcPtr)(int,int))
{
	printf("\n%s(%d)\n",__FUNCTION__, (int)funcPtr);
	/* check if the pointer passed to this function is
	 * not NULL before dereferencing it */
	if (funcPtr != NULL)
	{
		/* check if the pointer pointed to by funcPtr is
		 * not NULL before dereferencing it */
		if ( *funcPtr != NULL )
		{
			int result ;
			printf("Calling function pointer passed by-reference\n");
			result = (*funcPtr)(5, 6);
			printf("result = %d\n", result);
		}
		else
		{
			printf("Null pointer exception\n");
		}
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

void FunctionsAndPointers(void)
{
	int (*funcPtr)(int,int);
	int (**funcPtrToPtr)(int,int);

	funcPtr = &TestFunction;
	funcPtrToPtr = &funcPtr;

	printf("\n-----------------------\n");
	printf("Functions and pointers\n");
	printf("-----------------------\n\n");

	printf("\nCalling the Function directly\n");
	TestFunction(1, 2);

	printf("\nCalling the Function indirectly via pointer to function\n");
	ExecuteFunctionPassedbyValue(funcPtr);


	printf("\nCalling the Function indirectly via pointer to pointer to function\n");
	ExecuteFunctionPassedbyReference(funcPtrToPtr);
}
