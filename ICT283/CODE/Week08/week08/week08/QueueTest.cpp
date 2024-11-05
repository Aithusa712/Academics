// IntQueueTest Program
//
// Version
//   original by - Nicola Ritter
//   modified by smr
//
//---------------------------------------------------------

#include "Queue.h"
#include <iostream>
#include <ctime>
using namespace std;

//---------------------------------------------------------

const int EVENT_COUNT = 20;
const int MAX_NUM = 100;

//---------------------------------------------------------

typedef Queue<int> IntQueue;
typedef Queue<float> FloatQueue;

//---------------------------------------------------------

void DoEvents ();
void AddNumber (IntQueue &aqueue);
void DeleteNumber (IntQueue &aqueue);
void TestOverflow();

//---------------------------------------------------------

int main()
{
	DoEvents ();

	cout << endl;
	system("Pause");
	cout << endl;

	TestOverflow();

	cout << endl;
	return 0;
}

//---------------------------------------------------------

void DoEvents ()
{
 	IntQueue aqueue;

	// Seed random number generator
	srand (time(NULL));

	for (int count = 0; count < EVENT_COUNT; count++)
	{
		// Choose a random event
		int event = rand() % 5;

		// Do something based on that event type, biasing
		//   it towards Adding
		if (event <= 2) // event = 0, 1 or 2
		{
			AddNumber (aqueue);
		}
		else // event = 3 or 4
		{
			DeleteNumber (aqueue);
		}
	}
// aqueue is local so destructor for aqueue is called when routine finishes.
}

//---------------------------------------------------------

void AddNumber (IntQueue &aqueue)
{
	// Get a random number
	int num = rand() % (MAX_NUM+1);

	// Try adding it, testing if the aqueue was full
	if (aqueue.Enqueue(num))
	{
		cout.width(3);
		cout << num << " added to the queue" << endl;
	}
	else
	{
		cout.width(3);
		cout << "Overflow: could not add " << num << endl;
	}
}

//---------------------------------------------------------

void DeleteNumber (IntQueue &aqueue)
{
	int num;
	if (aqueue.Dequeue(num))
	{
		cout.width(3);
		cout << num << " deleted from the queue" << endl;
	}
	else
	{
		cout << "IntQueue is empty, cannot delete" << endl;
	}
}

//---------------------------------------------------------

void TestOverflow()
{
	Queue<double> mqueue;

	int count = 0;

	// Keeping adding numbers until we run out of space, will take //time
	while (mqueue.Enqueue(count))
	{
		count++;
		cout << "Count is " << count << endl;
	}

}

//---------------------------------------------------------
