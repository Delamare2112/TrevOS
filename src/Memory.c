#include "Memory.h"

unsigned int currentIndex = 0;

void* kmalloc(unsigned int size)
{
	unsigned int ret = EndOfKernel + currentIndex;
	currentIndex += size;
	return ret;
}

void free(void* addr)
{
	pageDirectory.nextPage = (int)addr>>22;
	pageDirectory.pages[pageDirectory.nextPage].flags |= 1 << 0;
}

void InitMMU()
{
	pageDirectory.pages = EndOfKernel; // place the begining of the pointer
	pageDirectory.startAddress = StartOfKernel;
	pageDirectory.pages[0].physicalAddress = StartOfKernel;
	pageDirectory.pages[0].virtualAddress = 0;
	pageDirectory.pages[0].flags = 1 << 0;
	pageDirectory.nextPage = 1;
}
