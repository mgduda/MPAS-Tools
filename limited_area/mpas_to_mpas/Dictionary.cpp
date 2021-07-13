#include "Dictionary.h"
#include <string.h>

Dictionary::Dictionary()
{
	Dictionary((size_t)100000);
}

Dictionary::Dictionary(size_t _maxsize)
{
	size = _maxsize;
	storage = new uint64_t [size];
	clear();
}

Dictionary::~Dictionary()
{
	delete [] storage;
}

bool Dictionary::insert(int n)
{
	int offset = n % 64;
	size_t pos = n / 64;

	if (n < 0 || pos >= size) {
		return false;
	}

	storage[pos] |= (1 << offset);

	return true;
}

bool Dictionary::query(int n)
{
	int offset = n % 64;
	size_t pos = n / 64;

	if (n < 0 || pos >= size) {
		return false;
	}

	return ((storage[pos] & (1 << offset)) != (uint64_t)0);
}

bool Dictionary::remove(int n)
{
	int offset = n % 64;
	size_t pos = n / 64;

	if (n < 0 || pos >= size) {
		return false;
	}

	storage[pos] &= ~(1 << offset);

	return true;
}

void Dictionary::clear()
{
	memset(storage, 0, sizeof(uint64_t) * size);
}
