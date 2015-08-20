#include "Memory.h"

// #define NODE_SPACE_SIZE 4194304
#define NODE_SPACE_SIZE 800

MemoryNode* freeMemory;
MemoryNode* usedMemory;
void* mainMemoryStart;

MemoryNode* usedTop;
MemoryNode* usedBottom;
MemoryNode* freeTop;
MemoryNode* freeBottom;

void ShowMemory()
{
	MemoryNode* currentNode = freeTop;
	WriteString("FREE:\n");
	for(int i = 0; currentNode->size != 0; i++)
	{
		WriteString(itoa(currentNode));
		WriteString(": "); WriteString(itoa(currentNode->size)); WriteString(": ");
		WriteString(itoa(currentNode->physicalAddress));WriteString(": ");
		WriteString(itoa(currentNode->next));
		WriteString("\n");
		currentNode = currentNode->next;
	}
	currentNode = usedTop;
	WriteString("USED:\n");
	for(int i = 0; currentNode != 0; i++)
	{
		WriteString(itoa(currentNode));
		WriteString(": "); WriteString(itoa(currentNode->size)); WriteString(": ");
		WriteString(itoa(currentNode->physicalAddress));WriteString(": ");
		WriteString(itoa(currentNode->next));
		WriteString("\n");
		currentNode = currentNode->next;
	}
	WriteString("\n");
}

void* kmalloc(unsigned int size)
{
	WriteString("allocating "); WriteString(itoa(size));
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
	WriteString(" at "); WriteString(itoa(ret)); WriteString("\n");
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
		if(!target)
		{
			WriteString(itoa(addr)); WriteString(" not found in allocation list\n");
			return;
		}
	}
	if(prev)
		prev->next = target->next;
	target->next = freeTop;
	freeTop = target;
}

void InitMMU()
{
	WriteString("Kernel at "); WriteString(itoa(StartOfKernel));
	WriteString("\nSetting up MMU at "); WriteString(itoa(EndOfKernel)); WriteString("\n");
	freeMemory = EndOfKernel;
	usedMemory = freeMemory + NODE_SPACE_SIZE;
	mainMemoryStart = usedMemory + NODE_SPACE_SIZE;

	usedTop = usedMemory;
	usedBottom = usedMemory + 1;
	freeTop = freeMemory;
	freeBottom = freeMemory + 1;
	unsigned int i;
	for(i = 1; i < (NODE_SPACE_SIZE / sizeof(MemoryNode)) - 1; i++)
	{
		freeMemory[i].next = freeMemory + 1 + i;
		usedMemory[i].next = usedMemory + 1 + i;
		// WriteString("Setting MemoryNode: "); WriteString(itoa(i)); WriteChar('\n');
	}
	freeTop->size = (void*)StartOfKernel - mainMemoryStart;
	// WriteString("freeTop size: "); WriteString(itoa(freeTop->size));
	freeTop->physicalAddress = mainMemoryStart;
	WriteString("\nMMU Setup with "); WriteString(itoa(i * 2)); WriteString(" nodes\n");
}