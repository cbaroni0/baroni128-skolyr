/**********************************************************
 * AUTHOR 		   : Chris Baroni
 * STUDENT ID      : 266549
 * ASSIGNMENT	   : 6
 * CLASS 		   : CS1D
 * SECTION 		   : M/W 4:30p-7:50p
 * DUE DATE 	   : 3/2/2016
 **********************************************************/

#ifndef PRIORITYQUEUE_H_
#define PRIORITYQUEUE_H_

#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct node
{
	int priority;	//highest number highest priority
	string name;
	bool operator<(const node& rhs) const
	{
	   return this->priority < rhs.priority;
	}
	bool operator>(const node& rhs) const
    {
	   return this->priority > rhs.priority;
    }
};

class PriorityQueue
{
public:
	PriorityQueue();
	~PriorityQueue();


	void push(int priority,
			  string newName); 	//inserts an element in the priority queue
	node pop(); 				//removes the element at the top of the priority queue
	node top(); 				//returns a constant reference to the largest element of the priority queue
	node at(int n);				//return node at specified location
	int size(); 				//returns the number of elements stored
	bool empty();				//returns a boolean to show if empty or not
	void sort();				//sorts based on priority


private:
	vector<node> list;
};

PriorityQueue::PriorityQueue()
{

}
PriorityQueue::~PriorityQueue(){}


void PriorityQueue::push(int priority,
		  string newName)
{
	node n;
	n.name = newName;
	n.priority = priority;
	list.push_back(n);
	sort();
}

node PriorityQueue::pop()
{
	node temp = list.at(list.size()-1);
	list.pop_back();
	return temp;
}

node PriorityQueue::top()
{
	return list[list.size()-1];
}

node PriorityQueue::at(int n)
{
	return list[n];
}

int PriorityQueue::size()
{
	return list.size();
}

bool PriorityQueue::empty()
{
	return list.empty();
}

void PriorityQueue::sort()
{
	node temp;
	for (int i = 0; i < list.size(); i++)
	{
			for (int j = i+1; j < list.size(); j++)
			{
				if (list[i].priority > list[j].priority)
				{
					temp = list[i];
					list[i] = list[j];
					list[j] = temp;
				}
			}
	}
}

#endif /* PRIORITYQUEUE_H_ */
