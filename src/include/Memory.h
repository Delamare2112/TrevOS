#pragma once
#include "kernel.h"

typedef struct
{
	char alloced;
	size_t allocSize;
	size_t freeSize;
} __attribute__((packed)) MemPrefix;

extern void LoadPageDirectory(unsigned int*);
extern void EnablePaging();
extern int StartOfKernel, EndOfKernel;

extern MemPrefix* MemPreTop;

void* kmalloc(unsigned int size);
void free(void* addr);
void memset(void* addr, size_t size, char value);
void InitMMU();
void ShowMemory();

