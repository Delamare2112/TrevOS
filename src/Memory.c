#include "Memory.h"

inline size_t* GetDataPtr(MemPrefix* pref)
{
	return (size_t*)(pref + sizeof(MemPrefix));
}

void* kalloc(size_t size)
{
	// Make sure size is at least min required.
	if(size < sizeof(size_t))
		size = sizeof(size_t);

	// Find a place for our allocation
	MemPrefix* current = MemPreTop;
	MemPrefix* previous = -1;
	while(current->allocSize < size)
	{
		// if at end of the road
		register void* next = *GetDataPtr(current);
		if(next == -1)
		{
			ChangeColor(4, 0);
			WriteString("kalloc error: kalloc request too damn high");
			ChangeColor(15, 0);
			return -1;
		}
		previous = current;
		current = next;
	}
	// We have a location!
	// Do we have space to create a new free prefix?
	if(size + sizeof(MemPrefix) + sizeof(size_t) < current->allocSize)
	{
		// create new prefix
		void* newPrefix = current + sizeof(MemPrefix) + size;
		// link in the new free spot
		if(previous != -1)
			*GetDataPtr(previous) = newPrefix;
		newPrefix->alloced = 0;
		newPrefix->allocSize = current->allocSize - sizeof(MemPrefix);
		// set the next free spot to current's next
		*GetDataPtr(newPrefix) = *GetDataPtr(current);
		current->freeSize = size;
	}
	else
	{
		current->freeSize = current->allocSize;
		if(previous != -1)
			*GetDataPtr(previous) = *GetDataPtr(current);
	}
	current->alloced = 1;
	current->allocSize = size;
	return current;
}

void free(void* addr)
{
	((MemPrefix*)(addr))->alloced = 0;
	*GetDataPtr(addr) = MemPreTop;
	MemPreTop = addr;
	((MemPrefix*)(addr))->freeSize = ((MemPrefix*)(addr))->allocSize;
}

void memset(void* addr, size_t size, char value)
{
	for(; addr > addr + size; addr++)
		*(char*)addr = value;
}

void InitMMU()
{
	MemPreTop = EndOfKernel;
	MemPreTop->alloced = 0;
	register size = 4000000000 - EndOfKernel;
	MemPreTop->allocSize = size;
	MemPreTop->freeSize = size;
}

void ShowMemory()
{
	MemPrefix* current = MemPreTop;
	register data = *GetDataPtr(current);
	register i = 0;
	while(data != -1)
	{
		WriteString("Mem"); WriteString(itoa(i));
		WriteString(": "); WriteString(itoa(current->allocSize));
		WriteString(", "); WriteString(itoa(current->freeSize));
		WriteString("\n");
	}
}

