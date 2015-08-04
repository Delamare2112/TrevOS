#pragma once

extern void LoadPageDirectory(unsigned int*);
extern void EnablePaging();
extern int StartOfKernel, EndOfKernel;

typedef struct Page
{
	char physicalAddress, virtualAddress, flags;
}__attribute__((packed)) Page;

typedef struct PageDirectory
{
	Page* pages;
	unsigned int nextPage;
	unsigned int startAddress;
} __attribute__((packed)) PageDirectory;

PageDirectory pageDirectory;

void* kmalloc(unsigned int size);
void InitMMU();