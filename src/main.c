/*
 * main.c
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
*   Public Functions Declarations
*----------------------------------------------------------------------
*/
extern void BasicPointers(void);
extern void ArrayAndPointers(void);
extern void PointersToPointers(void);
extern void FunctionsAndPointers(void);
extern void ArrayOfFunctionPointers(void);
extern void CastingPointers(void);
extern void VoidPointers(void);
extern void StructuresAndPointers(void);

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
int main(int argc, char *argv[])
{
	BasicPointers();

	ArrayAndPointers();

	PointersToPointers();

	FunctionsAndPointers();

	ArrayOfFunctionPointers();

	CastingPointers();

	VoidPointers();

	StructuresAndPointers();

	return 0;
}


/*
*----------------------------------------------------------------------
*   Export Functions Definitions
*----------------------------------------------------------------------
*/
