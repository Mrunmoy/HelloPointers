/*
 * array_and_pointers.c
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
#include<stdio.h>
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
static void GetIntArrayFromVarArray(int some_var[]);
static void GetIntArrayFromPtr(int *some_ptr);
static void ModifyIntArrayByUsingValue(int some_value[]);
static void ModifyIntArrayByUsingReference(int *some_ptr);
/*
*----------------------------------------------------------------------
*   Private Functions Definitions
*----------------------------------------------------------------------
*/

/* Passing an integer to a function "by-value" */
static void GetIntArrayFromVarArray(int some_var[])
{
	int iter;
	printf("\n%s(%d)\n", __FUNCTION__,(int)some_var);


	/* The value of the variable passed to this function is
	 * copied into some_var array when this function code is executed.
	 * we can get the value passed to this function by accessing
	 * some_var's array elements
	 * */
	printf("The values of varA array (passed to function by-value)\n");
	for(iter=0;iter<10;iter++)
	{
		printf("some_var[%d]: %d\n", iter, some_var[iter]);
	}
}

/* Passing an integer to a function "by-reference" */
static void GetIntArrayFromPtr(int *some_ptr)
{
	int iter;
	printf("\n%s(%d)\n", __FUNCTION__, (int)some_ptr);

	printf("The values of varA array (passed to function by-reference)\n");
	for(iter=0;iter<10;iter++)
	{
		/* since some_ptr is pointing to the array.
		 * it can be used with the [] operator to
		 * index into the array */
		printf("%d[%d]: %d\n", (int)some_ptr, iter, some_ptr[iter]);
	}

	printf("The values of varA array (accessed by adding index to pointer)\n");
	for(iter=0;iter<10;iter++)
	{
		/* since some_ptr is pointing to the array.
		 * it can be incremented to access the next element
		 * of the array by adding the index to the pointer to
		 * get the address of the next element, and then
		 * using the * operator to dereference the address
		 * to get to the value. */
		printf("*(%d + %d): %d\n", (int)some_ptr, iter, *(some_ptr + iter));
	}


	printf("The values of varA array (accessed by incrementing the pointer)\n");
	for(iter=0;iter<10;iter++)
	{
		/* since some_ptr is pointing to the array.
		 * it can be incremented to access the next element
		 * of the array by adding the index to the pointer to
		 * get the address of the next element, and then
		 * using the * operator to dereference the address
		 * to get to the value. */
		printf("*(%d): %d\n", (int)some_ptr, *(some_ptr));

		/* increment the pointer to point to the next element in the array */
		some_ptr++;
	}
}

/* Passing an integer array to a function "by-value"
 * Modifying the value by using the reference */
static void ModifyIntArrayByUsingValue(int some_value[])
{
	int iter;
	/* Since the variable's value is passed,
	 * we cannot modify the original variable's
	 * value, but we can modify the value of
	 * its copy which is in some_value
	 * */
	printf("\n%s(%d)\n", __FUNCTION__,(int)some_value);


	printf("The values of varA array (passed to function by-value)\n");
	for(iter=0;iter<10;iter++)
	{
		/* each element of varA array is copied into
		 * some_value array
		 * */
		printf("%d[%d]: %d\n", (int)some_value, iter, some_value[iter]);
	}

	/* Modify the value of elements of some_value array */
	for(iter=0;iter<10;iter++)
	{
		some_value[iter] = iter*2;
	}

	printf("The values of varA array modified (Modified by using value)\n");
	for(iter=0;iter<10;iter++)
	{
		printf("%d[%d]: %d\n", (int)some_value, iter, some_value[iter]);
	}
}

/* Passing an integer array to a function "by-reference"
 * Modifying the value by using the reference */
static void ModifyIntArrayByUsingReference(int *some_ptr)
{
	int iter;
	/* Since the variable's address is passed,
	 * we can use the dereference operator (*) to
	 * access and modify the variable's value
	 * */
	printf("\n%s(%d)\n", __FUNCTION__, (int)some_ptr);

	printf("The value of varA array (passed to function by-reference)\n");
	for(iter=0;iter<10;iter++)
	{
		/* each element of varA array are accessed by
		 * some_ptr directly using the [] operator
		 * */
		printf("%d[%d]: %d\n", (int)some_ptr, iter, some_ptr[iter]);
	}

	/* Modify the value of elements of some_ptr array */
	for(iter=0;iter<10;iter++)
	{
		some_ptr[iter] = iter*4;
	}

	printf("The values of varA array modified (Modified by using reference)\n");
	for(iter=0;iter<10;iter++)
	{
		printf("%d[%d]: %d\n", (int)some_ptr, iter, some_ptr[iter]);
	}
}



/*
*----------------------------------------------------------------------
*   Export Functions Definitions
*----------------------------------------------------------------------
*/

void ArrayAndPointers(void)
{
	/* define an integer array of 10 elements */
	int varA[10]; /* contains junk value because it is not initialized here */

	/* define a pointer to the integer */
	int *ptrA; /* contains junk value because it is not initialized here */

	int iter;

	/* lets first fill the array with some known values
	 * The array starts with index 0 and ends with
	 * index N-1 where N is the number of elements
	 * in the array.
	 *
	 * The "elements" of an array are simple
	 * variables of the same type of the array.
	 *
	 * The elements are accessed by using the []
	 * operator to index into the array.
	 *
	 * varA[0] will have 0
	 * varA[1] will have 1, etc
	 * */
	for(iter=0;iter<10;iter++)
	{
		varA[iter] = iter;
	}

	printf("\n-----------------------\n");
	printf("Arrays and Pointers usage\n");
	printf("-----------------------\n\n");
	printf("%s()\n", __FUNCTION__);

	/* set the integer pointer to point to the integer array.
	 * the & operator is not required here because varA itself
	 * is an integer pointer. So, an array and a pointer are
	 * equal. */
	ptrA = varA; /* ptrA gets the value of varA, ptrA now "points" to varA array */

	/* get the value of varA directly */
	printf("The value of varA is: %d (reading via varA)\n", (int)varA);
	printf("The value of varA is: %d (reading via ptrA, using ptrA = varA)\n", (int)ptrA);

	/* another way of assigning the address of the array to ptrA is
	 * by using the & operator. But in this case, we have to get the
	 * first variable (element) in the array and then get the address
	 * of that element.
	 * The [] operator gets the element in an array
	 * var[0] is the first element in the array and
	 * &varA[0] is the address of the first element in the
	 * array.
	 * */
	ptrA = &varA[0]; /* ptrA gets the address of first variable element in varA array,
	                    ptrA now "points" to varA array */

	printf("The value of varA is: %d (reading via ptrA, using ptr = &varA[0])\n", (int)ptrA);

	/* get the value of first element of varA array directly */
	printf("The value of first element of varA is: %d(reading via varA[0])\n", (int)varA[0]);

	/* get the value of first element of varA indirectly through ptrA
	 * since ptrA now points to varA array,
	 * to get the value of varA, we need to "de-reference" the
	 * pointer ptrA by using a "*" operator preceding ptrA
	 * */
	printf("The value of first element of varA is: %d (reading via ptrA)\n", *ptrA);

	/* Pass varA array by-value */
	GetIntArrayFromVarArray(varA);

	/* Pass varA by-reference */
	GetIntArrayFromPtr(varA);

	/* Try to modify values of varA array by passing by-value */
	ModifyIntArrayByUsingValue(varA);
	printf("The value of varA array after call to ModifyIntArrayByUsingValue(varA)\n");
	for(iter=0;iter<10;iter++)
	{
		printf("varA[%d]: %d\n", iter, varA[iter]);
	}

	/* Try to modify values of varA array by passing by-reference */
	ModifyIntArrayByUsingReference(varA);
	printf("The value of varA after call to ModifyIntByUsingReference(varA)\n");
	for(iter=0;iter<10;iter++)
	{
		printf("varA[%d]: %d\n", iter, varA[iter]);
	}

	printf("\nYou see, arrays cannot be passed by-value!\n");
	printf("\n");
	printf("-----------------------\n\n");
}
