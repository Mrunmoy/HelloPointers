/*
 * structures_and_pointers.c
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
typedef struct myStruct_t
{
	int varA;
	char varB;
	float varC;
}myStruct_t;

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
static void StructPassbyValue(myStruct_t some_var);
static void StructPassbyReference(myStruct_t *some_ptr);

/*
*----------------------------------------------------------------------
*   Private Functions Definitions
*----------------------------------------------------------------------
*/
static void StructPassbyValue(myStruct_t some_var)
{
	printf("\n%s(some_var)\n", __FUNCTION__);

	/* the structure is passed by value into
	 * this function. Each member of the variable
	 * stA is copied into each member of the
	 * parameter some_var. */
	printf("Value of structure passed by-value is:\n");
	printf("some_var.varA = %d\n", some_var.varA);
	printf("some_var.varB = %c\n", some_var.varB);
	printf("some_var.varC = %02.02f\n", some_var.varC);

	printf("The entire structure is copied on the call-stack\n");
}

static void StructPassbyReference(myStruct_t *some_ptr)
{
	printf("\n%s(%d)\n", __FUNCTION__, (int)some_ptr);
	
	if (some_ptr != NULL)
	{
		/* the structure is passed by reference into
		 * this function. the parameter some_ptr
		 * contains the pointer to the variable stA.
		 * The members of a structure pointer can be
		 * accessed by using the "->" operator
		 * to dereference into the structure.
		 * */
		printf("Value of structure passed by-reference is:\n");
		printf("some_var.varA = %d\n", some_ptr->varA);
		printf("some_var.varB = %c\n", some_ptr->varB);
		printf("some_var.varC = %02.02f\n", some_ptr->varC);
	}
	else
	{
		printf("Null pointer exception!\n");
	}
	printf("Only the structure pointer is copied on the call-stack\n");
}


/*
*----------------------------------------------------------------------
*   Export Functions Definitions
*----------------------------------------------------------------------
*/

void StructuresAndPointers(void)
{
	myStruct_t stA;
	myStruct_t * struct_ptr;

	printf("\n-----------------------\n");
	printf("Structures and pointers\n");
	printf("-----------------------\n\n");
	printf("%s()\n", __FUNCTION__);

	/* Fill in values for member variables */
	stA.varA = 5;
	stA.varB = 'A';
	stA.varC = 20.9f;

	/* use struct_ptr to point to stA
	 * Again, & is used to get the
	 * address of structure variable stA
	 *  */
	struct_ptr = &stA;
	printf("Address of structure is %d (using pointer to structure variable)\n", (int)struct_ptr);

	/* Pass by-value */
	StructPassbyValue(stA);

	/* Pass by-value */
	StructPassbyReference(struct_ptr);

	printf("\nThe advantage of passing structure by reference is\n"
			"you can pass a bunch of parameters using only\n"
			"one pointer. Thus saving valuable stack space.");

}
