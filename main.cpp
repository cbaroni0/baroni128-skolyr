/********************************************
* Names: Chris Baroni, Nick Bernstein, Pierce Findlay
* CS 311 MTW 5pm-8pm
********************************************/

#include "header.h"

int main()
{
	//outputs header
	PrintHeader("Priority Queues", "Chris Baroni", "266549", 'a', 6);
	//outputs a quick explanation of how the code works
	cout << "/*********************************************************\n"
		 << "* This code implements a custom Priority Queue object\n"
		 << "* and the STL Priority Queue object in the form of a\n"
		 << "* hospital waiting list. The doctor sees each patient for\n"
		 << "* 20 minutes then sends them home. However, an emergency\n"
		 << "* case is set at 2 different time points that the doctor\n"
		 << "* must immediately attend to then returns to the previous\n"
		 << "* patient\n"
		 << "*********************************************************/\n\n";

	PriorityQueue *hospital = new PriorityQueue(); //priority queue using object I made
	priority_queue<node> pq; //stl priority queue
	int hour;	//counters used to keep track
	int minute;	//of time
	hour = 12;
	minute = 0;

	//initializes PriorityQueue hospital list
	initializeHospital(*hospital);
	//initializing priority_queue hospital2 list
	node temp;
	temp.name = "Alice Ailment";
	temp.priority = 3;
	pq.push(temp);
	temp.name = "Irene Ill";
	temp.priority = 1;
	pq.push(temp);
	temp.name = "Sid Sickly";
	temp.priority = 4;
	pq.push(temp);
	temp.name = "Cathy Coughing";
	temp.priority = 5;
	pq.push(temp);
	temp.name = "Bob Bleeding";
	temp.priority = 8;
	pq.push(temp);
	temp.name = "Frank Feelingbad";
	temp.priority = 7;
	pq.push(temp);
	temp.name = "Sam Sneezing";
	temp.priority = 5;
	pq.push(temp);


	/***********************************************************************
	 * Purpose: goes through entire hospital wait list and remove each
	 * patient after 20 minutes. also checks for emergencies
	 ***********************************************************************/
	cout << "*** BEGINNING PRIORITYQUEUE OBJECT TEST ***\n";
	while(!hospital->empty())
	{

		//outputs hospital waiting list
		cout << "Wait List\n";
		cout << left << setw(16) << "Name" << "Waiting(hours)\n";
		for(int i = hospital->size()-1; i > -1; i--)
		{
			cout << left << setw(16) << hospital->at(i).name << right
				 << setw(14) << hospital->at(i).priority << endl;
		}

		//for loop keeps track of the 20 minutes
		//that each patient experiences and checks for
		//emergency patients arriving
		cout << "\nNow treating " << hospital->top().name << endl;
		for(int i = 0; i < 20; i++)
		{
			//EMERGENCY FOR PAULA PAIN
			if(hour == 1 && minute == 19)
			{
				//adds paula pain to wait list at top of priority
				cout << "\n\nEMERGENCY PATIENT - PAULA PAIN\n";
				hospital->push(100, "Paula Pain");
				//20 minutes of emergency patient taken care of
				for(int i = 0; i < 20; i++)
				{
					cout << 20 - i << " ";

					//increments time
					minute++;
					if(minute == 60)
					{
						minute = 0;
						//if statement for hour == 12
						(hour == 12) ? hour = 1 : hour++;

					}//endIF
				}//endFOR
				//states when a patient finished their treatment
				cout << endl << hospital->top().name << " treatment completed at "
					 << hour << ":";
				if(minute == 0)
					cout << "00" << "\n\n\n";
				else
					cout << minute << "\n\n\n";
				hospital->pop();
				cout << "Continuing treatment of " << hospital->top().name << endl;
			}//end PAULA PAIN EMERGENCY

			//EMERGENCY FOR TOM TEMPERATURE
			else if(hour == 2 && minute == 21)
			{
				//adds tom temperature to top of wait list
				cout << "\n\nEMERGENCY PATIENT - TOM TEMPERATURE\n";
				hospital->push(100, "Tom Temperature");
				for(int i = 0; i < 20; i++)
				{
					cout << 20 - i << " ";

					//increments time
					minute++;
					if(minute == 60)
					{
						minute = 0;
						//if statement for hour == 12
						(hour == 12) ? hour = 1 : hour++;

					}//endIF
				}//endFOR
				//tates when a patient ended their treatment
				cout << endl << hospital->top().name << " treatment completed at "
							 << hour << ":";
						if(minute == 0)
							cout << "00" << "\n\n\n";
						else
							cout << minute << "\n\n\n";
				hospital->pop();
				cout << "Continuing treatment of " << hospital->top().name << endl;
			}//end TOM TEMPERATURE EMERGENCY

			cout << 20 - i << " ";

			//increments time
			minute++;
			if(minute == 60)
			{
				minute = 0;
				//if statement for hour == 12
				(hour == 12) ? hour = 1 : hour++;
			}//endIF
		}// endFOR

		//states when patient finished their treatment
		cout << endl << hospital->top().name << " treatment completed at "
			 << hour << ":";
		if(minute == 0)
			cout << "00" << "\n\n\n";
		else
			cout << minute << "\n\n\n";
		hospital->pop();
	}// endWHILE
	cout << "ALL PATIENTS TREATED\n";
	cout << "*** ENDING PRIORITYQUEUE OBJECT TEST ***\n\n\n";
	/***********************************************************************/


	//reininitialize time
	hour = 12;
	minute = 0;
	/***********************************************************************
	 * Purpose: goes through entire pq wait list and remove each
	 * patient after 20 minutes. also checks for emergencies
	 ***********************************************************************/
	cout << "*** BEGINNING priority_queue STL OBJECT TEST ***\n";
	while(!pq.empty())
	{
		//CALC & OUT - for loop keeps track of the 20 minutes
		//	that each patient experiences and checks for
		//	emergency patients arriving
		cout << "Now treating " << pq.top().name << endl;
		for(int i = 0; i < 20; i++)
		{
			//EMERGENCY FOR PAULA PAIN
			if(hour == 1 && minute == 19)
			{
				//adds paula pain to wait list at top of priority
				cout << "\n\nEMERGENCY PATIENT - PAULA PAIN\n";
				temp.name = "Paula Pain";
				temp.priority = 100;
				pq.push(temp);
				//20 minutes of emergency patient taken care of
				for(int i = 0; i < 20; i++)
				{
					cout << 20 - i << " ";

					//increments time
					minute++;
					if(minute == 60)
					{
						minute = 0;
						//if statement for hour == 12
						(hour == 12) ? hour = 1 : hour++;

					}//endIF
				}//endFOR
				//states when a patient finished their treatment
				cout << endl << pq.top().name << " treatment completed at "
					 << hour << ":";
				if(minute == 0)
					cout << "00" << "\n\n\n";
				else
					cout << minute << "\n\n\n";
				pq.pop();
				cout << "Continuing treatment of " << pq.top().name << endl;
			}//end PAULA PAIN EMERGENCY

			//EMERGENCY FOR TOM TEMPERATURE
			else if(hour == 2 && minute == 21)
			{
				//adds tom temperature to top of wait list
				cout << "\n\nEMERGENCY PATIENT - TOM TEMPERATURE\n";
				temp.name = "Tom Temperature";
				temp.priority = 100;
				pq.push(temp);
				for(int i = 0; i < 20; i++)
				{
					cout << 20 - i << " ";

					//increments time
					minute++;
					if(minute == 60)
					{
						minute = 0;
						//if statement for hour == 12
						(hour == 12) ? hour = 1 : hour++;

					}//endIF
				}//endFOR
				//states when a patient ended their treatment
				cout << endl << pq.top().name << " treatment completed at "
							 << hour << ":";
						if(minute == 0)
							cout << "00" << "\n\n\n";
						else
							cout << minute << "\n\n\n";
				pq.pop();
				cout << "Continuing treatment of " << pq.top().name << endl;
			}//end TOM TEMPERATURE EMERGENCY

			cout << 20 - i << " ";

			//increments time
			minute++;
			if(minute == 60)
			{
				minute = 0;
				//if statement for hour == 12
				(hour == 12) ? hour = 1 : hour++;
			}//endIF
		}// endFOR

		//states when patient finished their treatment
		cout << endl << pq.top().name << " treatment completed at "
			 << hour << ":";
		if(minute == 0)
			cout << "00" << "\n\n\n";
		else
			cout << minute << "\n\n\n";
		pq.pop();
	}// endWHILE

	cout << "ALL PATIENTS TREATED\n";
	cout << "*** ENDING priority_queue STL OBJECT TEST ***\n";
	/***********************************************************************/
	return 0;
}

/********************************************
* initializeHospital
* Purpose: function used to initialize the
* stl priority queue
********************************************/
void initializeHospital(PriorityQueue& list)
{
	list.push(3, "Alice Ailment");
	list.push(1, "Irene Ill");
	list.push(4, "Sid Sickly");
	list.push(5, "Cathy Coughing");
	list.push(8, "Bob Bleeding");
	list.push(7, "Frank Feelingbad");
	list.push(5, "Sam Sneezing");
}
