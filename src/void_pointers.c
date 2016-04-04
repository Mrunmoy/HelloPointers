/*
 * void_pointers.c
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


/*
*----------------------------------------------------------------------
*   Private Functions Definitions
*----------------------------------------------------------------------
*/

void UseVoidPtrAsInteger(void *vPtr)
{
	if (vPtr != NULL)
	{
		printf("%s(%d)\n", __FUNCTION__, (int)vPtr);
		printf("When dereferenced as an integer, the value is: %d\n", *((int *)vPtr));
	}
	else
	{
		printf("Null Pointer Excception!\n");
	}
}

void UseVoidPtrAsChar(void *vPtr)
{
	if (vPtr != NULL)
	{
		printf("%s(%d)\n", __FUNCTION__, (int)vPtr);
		printf("When dereferenced as an char, the value is: %c\n", *((char *)vPtr));
	}
	else
	{
		printf("Null Pointer Excception!\n");
	}
}



/*
*----------------------------------------------------------------------
*   Export Functions Definitions
*----------------------------------------------------------------------
*/

void VoidPointers(void)
{
	int varA = 15;
	char varB = 'A';
	void *voidPtr = NULL;

	printf("\n-----------------------\n");
	printf("Void pointers\n");
	printf("-----------------------\n\n");
	printf("%s()\n", __FUNCTION__);

	/* point to an integer variable */
	voidPtr = (void*)&varA;
	printf("\nUsing void pointer to point to an integer\n");
	UseVoidPtrAsInteger(voidPtr);

	/* now point to an char variable */
	voidPtr = (void*)&varB;
	printf("\nUsing void pointer to point to an char\n");
	UseVoidPtrAsChar(voidPtr);

	printf("\nVoid pointers can point to any data type.\n"
			"That gives us opportunity to use it to cast to any type\n"
			"depending upon our requirements.\n\n");

}
