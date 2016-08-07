#include "Utility.h"

// strlen is in C standard but we live outside the standard so we write our own.
size_t strlen(const char* str) {
	size_t size = 0;
	while(str[size] != 0)
		size++;
	return size;
}
