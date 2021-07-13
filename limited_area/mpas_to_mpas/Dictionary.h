#ifndef _DICTIONARY_H
#define _DICTIONARY_H

#include <stdint.h>
#include <cstddef>

class Dictionary
{
public:
	Dictionary();
	Dictionary(size_t maxsize);
	~Dictionary();
	bool insert(int n);
	bool query(int n);
	bool remove(int n);
	void clear();
private:
	size_t size;
	uint64_t *storage = NULL;
};

#endif
