#include "Memory.h"

unsigned char mainMemory[300];
unsigned int memoryIndex = 0;

void* malloc(unsigned int size)
{
	void* ret = mainMemory + memoryIndex;
	memoryIndex += size;
	return ret;
}
