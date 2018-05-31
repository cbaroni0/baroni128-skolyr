/**********************************************************
 * Names: Chris Baroni, Nick Bernstein, Pierce Findlay
 * Class: CPSC 311 MWT 5pm-8pm
 **********************************************************/

#ifndef PRIORITYQUEUE_H_
#define PRIORITYQUEUE_H_

#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct node
{
	//highest number highest priority
	int priority;
	//name of patient	
	string name;
	//overloaded < operator
	bool operator<(const node& rhs) const
	{
	   return this->priority < rhs.priority;
	}
	//overloaded > operator
	bool operator>(const node& rhs) const
    {
	   return this->priority > rhs.priority;
    }
};

class PriorityQueue
{
public:
	//default ctor
	PriorityQueue();
	//default dtor
	~PriorityQueue();

	//append to the queue
	void push(int priority, string newName);
	//remove front element of the queue
	node pop();
	//return highest priority element
	node top();
	//return node at an index
	node at(int n);
	//return size of queue
	int size();
	//True if queue is empty
	bool empty();
	//Sorts queue
	void sort();

private:
	vector<node> list;
};

/********************************************
* Default Constructor
********************************************/
PriorityQueue::PriorityQueue(){}

/********************************************
* Default Destructor
********************************************/
PriorityQueue::~PriorityQueue(){}

/********************************************
* void push(int, string)
* Purpose: appends a node to the PriorityQueue
********************************************/
void PriorityQueue::push(int priority,
		  string newName)
{
	node n;
	n.name = newName;
	n.priority = priority;
	list.push_back(n);
	sort();
}

/********************************************
* node pop()
* Purpose: removes the element at the top of the PriorityQueue
********************************************/
node PriorityQueue::pop()
{
	node temp = list.at(list.size()-1);
	list.pop_back();
	return temp;
}

/********************************************
* node top()
* Purpose: returns node with the highest priority
********************************************/
node PriorityQueue::top()
{
	return list[list.size()-1];
}

/********************************************
* node at(int)
* Purpose: return node at specified location
********************************************/
node PriorityQueue::at(int n)
{
	return list[n];
}

/********************************************
* int size()
* Purpose: returns the number of elements stored
********************************************/
int PriorityQueue::size()
{
	return list.size();
}

/********************************************
* bool empty()
* Purpose: returns a boolean to show if empty or not
********************************************/
bool PriorityQueue::empty()
{
	return list.empty();
}

/********************************************
* void sort()
* Purpose: sorts based on priority
*********************************************/
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
