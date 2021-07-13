#include "Queue.h"

Queue::Queue()
{
	Queue((size_t)100000);
}

Queue::Queue(size_t _maxsize)
{
	maxsize = _maxsize + 1;  // One place in the circular buffer is reserved to indicate an empty queue
	storage = new int [maxsize];
}

Queue::~Queue()
{
	delete [] storage;
}

bool Queue::is_empty()
{
	return (head == tail);
}

bool Queue::insert(int n)
{
	if ((head + 1) % maxsize == tail) {
		return false; // queue is full
	}

	storage[head] = n;
	head = (head + 1) % maxsize;

	return true;
}

int Queue::remove()
{
	int temp;

	if (is_empty()) {
		return -1;
	}

	temp = storage[tail];
	tail = (tail + 1) % maxsize;
	
	return temp;
}

size_t Queue::size()
{
	return (head + maxsize - tail) % maxsize;
}
