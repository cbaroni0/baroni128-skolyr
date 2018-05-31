/**********************************************************
* Names: Chris Baroni, Nick Bernstein, Pierce Findlay
* CPSC 311 MTW 5pm-8pm
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
 ************************************************************************/
void PrintHeader(string asName,			//IN-OUT Assignment name
				 string authors,		//IN-OUT programmer
				 string id,				//IN-OUT student id #s
				 char asType,			//IN-OUT if assignment or lab
				 int asNum)				//IN-OUT assignment or lab number

{
        //This section below outputs the programmers' names, ID numbers, and class
	cout << left;
	cout << "******************************************************\n";
	cout << "* Programmed by : " << authors;
	cout << "\n* " << setw(14) << "Student Id" << ": " << id;
	cout << "\n* " << setw(14) << "Class" << ": CPSC 311 --> MTW - 5:00-"
			"8:00p \n";
	// This if selection statement will check to see if the input is a lab
	// or an assignment
	if (toupper(asType)== 'L') // If the type is L it will print Lab and it's number
	{
		cout << setw(15) << "* LAB #"
			 << asNum << ": " << asName;
	}
	else if (toupper(asType) == 'A')  // If the type is A it will print Assignment and it's number
	{
		cout << setw(15) << "* ASSIGNMENT #"
			 << asNum << ": " << asName;
	}
	else
	{
	        cout << setw(16) << "* EXCERCISE "  // If it is neither A or L then it prints Exercise
			 << ": " << asName;
	}

	cout << "\n******************************************************\n\n";
	cout << right;
} // EndPrintHeader
