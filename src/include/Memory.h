#pragma once

extern void LoadPageDirectory(unsigned int*);
extern void EnablePaging();
extern int StartOfKernel, EndOfKernel;

typedef struct
{
	unsigned int physicalAddress;
	struct MemoryNode* next;
	unsigned int size;
} __attribute__((packed)) MemoryNode;

void* kmalloc(unsigned int size);
void free(void* addr);
void InitMMU();