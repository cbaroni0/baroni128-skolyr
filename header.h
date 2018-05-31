/**********************************************************
 * Names: Chris Baroni, Nick Bernstein, Pierce Findlay
 * Class: CPSC 311 MWT 5pm-8pm
 **********************************************************/

/*********************************************************
* This code implements a custom Priority Queue object
* and the STL Priority Queue object in the form of a
* hospital waiting list. The doctor sees each patient for
* 20 minutes then sends them home. However, an emergency
* case is set at 2 different time points that the doctor
* must immediately attend to then returns to the previous
* patient
*********************************************************/

#ifndef HEADER_H_
#define HEADER_H_

#include <string>
#include <iomanip>
#include <iostream>
#include <queue>
#include "PriorityQueue.h"
using namespace std;

//PrintHeader - prints the header of relevant information at the top of the output.
void PrintHeader(string asName, string authors,	string id, char asType, int asNum);
//initializeHospital - initializes a PriorityQueue variable to be used by the main function.
void initializeHospital(PriorityQueue& list);

#endif /* HEADER_H_ */
