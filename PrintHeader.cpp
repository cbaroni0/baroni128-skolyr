/**********************************************************
 * AUTHOR 		   : Chris Baroni
 * STUDENT ID      : 266549
 * ASSIGNMENT	   : 6
 * CLASS 		   : CS1D
 * SECTION 		   : M/W 4:30p-7:50p
 * DUE DATE 	   : 3/2/2016
 **********************************************************/

#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

/************************************************************************
 * FUNCTION PrintHeader
 * _______________________________________________________________________
 * This Function receives and assignment name, type
 * and number then outputs the appropriate header -
 * returns nothing
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 	asName : Assignment Name has to be previously defined
 * 	asType : Assignment Type has to be previously defined
 * 	asNum  : Assignment Number has to be previously defined
 *
 * POST-CONDITIONS
 * 	This function will out the class heading.
 ************************************************************************/
void PrintHeader(string asName,			//IN-OUT Assignment name
				 string authors,		//IN-OUT programmer
				 string id,				//IN-OUT student id #s
				 char asType,			//IN-OUT if assignment or lab
				 int asNum)				//IN-OUT assignment or lab number

{
	cout << left;
	cout << "******************************************************\n";
	cout << "* Programmed by : " << authors;
	cout << "\n* " << setw(14) << "Student Id" << ": " << id;
	cout << "\n* " << setw(14) << "Class" << ": CS 1D --> MW - 4:30-"
			"8:00p \n";
	// This if selection statement will check to see if the input is a lab
	// or an assignment
	if (toupper(asType)== 'L')
	{
		cout << setw(15) << "* LAB #"
			 << asNum << ": " << asName;
	}
	else if (toupper(asType) == 'A')
	{
		cout << setw(15) << "* ASSIGNMENT #"
			 << asNum << ": " << asName;
	}
	else
	{
		cout << setw(16) << "* EXCERCISE "
			 << ": " << asName;
	}

	cout << "\n******************************************************\n\n";
	cout << right;
}
