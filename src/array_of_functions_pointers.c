/*
 * array_of_functions_pointers.c
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
#define MAX_FUNCTIONS		(4)

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

/* This enum is used to access the elements of
 * the calculator array using names instead of
 * numbers */
typedef enum Operations_t
{
	ADD=0,
	SUBTRACT,
	MULTIPLY,
	DIVIDE,
	MAX_OPERATIONS
}Operations_t;

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
static int Add(int a, int b);
static int Subtract(int a, int b);
static int Multiply(int a, int b);
static int Divide(int a, int b);

/*
*----------------------------------------------------------------------
*   Private Functions Definitions
*----------------------------------------------------------------------
*/
/* This is a array of function pointers */
static int (*Calculate[MAX_FUNCTIONS])(int, int) =
{
		Add,
		Subtract,
		Multiply,
		Divide
};

/* Adds two numbers and returns sum */
static int Add(int a, int b)
{
	printf("%s(%d,%d)\n", __FUNCTION__, a, b);
	return (a+b);
}

/* Subtracts two numbers and returns difference */
static int Subtract(int a, int b)
{
	printf("%s(%d,%d)\n", __FUNCTION__, a, b);
	return (a-b);
}

/* Multiplies two numbers and returns product */
static int Multiply(int a, int b)
{
	printf("%s(%d,%d)\n", __FUNCTION__, a, b);
	return (a*b);
}

/* Divides two numbers and returns quotient */
static int Divide(int a, int b)
{
	printf("%s(%d,%d)\n", __FUNCTION__, a, b);

	/* check if denominator is zero */
	if ( b != 0)
	{
		return (a/b);
	}

	printf("\ndivide by zero!\n");
	return 0;
}





/*
*----------------------------------------------------------------------
*   Export Functions Definitions
*----------------------------------------------------------------------
*/
void ArrayOfFunctionPointers(void)
{
	Operations_t oper;

	printf("\n-----------------------\n");
	printf("Array of Functions pointers\n");
	printf("-----------------------\n\n");

	for (oper = ADD; oper < MAX_OPERATIONS; oper++)
	{
		/* index into the Function Pointer array using the enumerator
		 * with the [] operator in the same was as accessing an array
		 * element. Then use the () operator to call the function
		 * pointed to by that array element.
		 *
		 * Passing 10 and 5 as function arguments.
		 * */
		int result = Calculate[oper](10, 5);
		printf("result = %d\n\n", result);
	}
}
