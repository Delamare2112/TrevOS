/*
	This is HEAVILY based on (pretty much is) liballoc from blanham's github.
	https://github.com/blanham/liballoc
	Thank you blanham for providing an example of memory allocation for me to learn from!
*/

#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define MAXEXP 32 // Max exponent for memory math
#define MINEXP 8  // Min exponent for memory math
#define MALLOC_MAGIC 0xc001c0de

struct BoundryTag
{
	unsigned int magic, size, realSize;
	int index;
	// OMG it's a linked list!
	struct BoundryTag* splitRight;
	struct BoundryTag* splitLeft;
	struct BoundryTag* next;
	struct BoundryTag* prev;
};
