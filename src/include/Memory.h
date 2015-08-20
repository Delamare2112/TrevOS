#pragma once
#include "kernel.h"

extern void LoadPageDirectory(unsigned int*);
extern void EnablePaging();
extern int StartOfKernel, EndOfKernel;

typedef struct
{
	void* physicalAddress;
	struct MemoryNode* next;
	int size;
} __attribute__((packed)) MemoryNode;

void* kmalloc(unsigned int size);
void free(void* addr);
void InitMMU();
void ShowMemory();