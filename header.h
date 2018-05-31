/**********************************************************
 * AUTHOR 		   : Chris Baroni
 * STUDENT ID      : 266549
 * ASSIGNMENT	   : 6
 * CLASS 		   : CS1D
 * SECTION 		   : M/W 4:30p-7:50p
 * DUE DATE 	   : 3/2/2016
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

void PrintHeader(string asName,			//IN-OUT Assignment name
				 string authors,		//IN-OUT programmer
				 string id,				//IN-OUT student id #s
				 char asType,			//IN-OUT if assignment or lab
				 int asNum);			//IN-OUT assignment or lab number
void initializeHospital(PriorityQueue& list);	//initialize hospital list

#endif /* HEADER_H_ */
