#ifndef _QUEUE_H
#define _QUEUE_H

#include <cstddef>

class Queue
{
public:
	Queue();
	Queue(size_t _maxsize);
	~Queue();
	bool is_empty();
	bool insert(int n);
	int remove();
	size_t size();
private:
	size_t head = 0;
	size_t tail = 0;
	size_t maxsize = 0;
	int *storage = NULL;
};

#endif
