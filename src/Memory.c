#include "Memory.h"

// #define NODE_SPACE_SIZE 4194304
#define NODE_SPACE_SIZE 800

MemoryNode* freeMemory;
MemoryNode* usedMemory;
unsigned int* mainMemoryStart;

MemoryNode* usedTop;
MemoryNode* usedBottom;
MemoryNode* freeTop;
MemoryNode* freeBottom;

void* kmalloc(unsigned int size)
{
	// WriteString("allocating "); WriteString(itoa(size)); WriteChar('\n');
	MemoryNode* oldUsedButtomNext = usedBottom->next;

	MemoryNode* freeNode = freeTop;
	while(freeNode->size < size)
		freeNode = freeNode->next;
	// if(freeNode->size != size && freeNode != freeMemory)
	// {
	// 	MemoryNode* oldFreeButtomNext = freeBottom->next;

	// 	freeBottom->size = freeNode->size - size;
	// 	freeBottom->next = freeTop;
	// 	freeTop = freeBottom;
	// 	freeBottom = oldFreeButtomNext;
	// }

	usedTop->size = size;
	usedTop->physicalAddress = freeNode->physicalAddress;
	void* ret = usedTop->physicalAddress;
	usedBottom->next = usedTop;
	usedTop = usedBottom;
	usedBottom = oldUsedButtomNext;

	freeNode->physicalAddress += size;
	freeNode->size -= size;
	return ret;
}

void free(void* addr)
{
	MemoryNode* target = usedTop;
	MemoryNode* prev = 0;
	while(target->physicalAddress != addr)
	{
		prev = target;
		target = target->next;
	}
	if(prev)
		prev->next = target->next;
	target->next = freeTop;
	freeTop = target;
}

void InitMMU()
{
	WriteString("Setting up MMU\n");
	freeMemory = EndOfKernel;
	usedMemory = freeMemory + NODE_SPACE_SIZE;
	mainMemoryStart = usedMemory + NODE_SPACE_SIZE;

	usedTop = usedMemory;
	usedBottom = usedMemory + 1;
	freeTop = freeMemory;
	freeBottom = freeMemory + 1;
	unsigned int i;
	// WriteString("about to write until"); WriteString(itoa(50)); WriteChar('\n');
	for(i = 1; i < (NODE_SPACE_SIZE / sizeof(MemoryNode)) - 1; i++)
	{
		freeMemory[i].next = freeMemory + 1 + i;
		usedMemory[i].next = usedMemory + 1 + i;
		// WriteString("Setting MemoryNode: "); WriteString(itoa(i)); WriteChar('\n');
	}
	freeTop->size = (unsigned int*)4294967296 - mainMemoryStart;
	freeTop->physicalAddress = mainMemoryStart;
	WriteString("MMU Setup with "); WriteString(itoa(i * 2)); WriteString(" nodes\n");
}