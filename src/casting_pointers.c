/*
 * casting_pointers.c
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
#define MAX_ELEMENTS	(4)

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



/*
*----------------------------------------------------------------------
*   Export Functions Definitions
*----------------------------------------------------------------------
*/

void CastingPointers(void)
{
	char cha[MAX_ELEMENTS] = { 20, 30, 40, 50 };
	char *char_ptr;
	int ita[MAX_ELEMENTS] = { 1, 2, 3, 4 };
	int *int_ptr;

	int iter;

	printf("\n-----------------------\n");
	printf("Casting pointers\n");
	printf("-----------------------\n\n");

	printf("Using char pointer to point to char array\n");
	char_ptr = cha;
	for(iter=0;iter<MAX_ELEMENTS;iter++)
	{
		printf("%d is at address %d, size of char is %d byte(s)\n", char_ptr[iter], (int)(char_ptr+iter), sizeof(char));
	}
	printf("\n");

	printf("Using integer pointer to point to integer array\n");
	int_ptr = ita;
	for(iter=0;iter<MAX_ELEMENTS;iter++)
	{
		printf("%d is at address %d, size of integer is %d byte(s)\n", int_ptr[iter], (int)(int_ptr+iter), sizeof(int));
	}
	printf("\n");

	printf("Using integer pointer to point to char array\n");
	int_ptr = (int *)cha;
	for(iter=0;iter<MAX_ELEMENTS;iter++)
	{
		printf("%d is at address %d, size of integer is %d byte(s)\n", int_ptr[iter], (int)(int_ptr+iter), sizeof(int));
	}
	printf("\n");

	printf("Using char pointer to point to integer array\n");
	char_ptr = (char *)ita;
	for(iter=0;iter<MAX_ELEMENTS;iter++)
	{
		printf("%d is at address %d, size of char is %d byte(s)\n", char_ptr[iter], (int)(char_ptr+iter), sizeof(char));
	}

	printf("\nYou see, how changing the pointer type from the data type\n"
			"accesses elements at different locations!\n"
			"This is due to the size of the data pointed to by the pointer.\n"
			"The pointer will advance by the amount which = size of the data type it points to.\n"
			"Also when dereferencing the pointer of any type will try to read\n"
			"the size of the data type it points to.\n\n");
}

