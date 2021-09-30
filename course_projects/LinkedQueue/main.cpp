#include <iostream>
#include "LinkedQueue.hpp"

using namespace std;

int main()
{
	LinkedQueue queue;

	for (int i = 1; i <= 16; i++) //default size is 16 for queue's array
	{
		queue.enqueue(i * 100);
	}

	while (!queue.isEmpty())
	{
		cout << "Dequeued " << queue.dequeue() << endl;
	}

	//dequeue error
	queue.dequeue();

	//alternating to test "circular" capabilities
	for (int i = 0; i < 20; i++)
	{
		cout << "Just enqueued " << (i * 10) << endl;
		queue.enqueue(i * 10);
		if (i % 3 == 0)
		{
			//NOTICE:  This is invalid if the queue is empty, it
			//will return 0
			cout << "\nJust dequeued " << queue.dequeue() << endl << endl;
		}
	}

	return 0;
}