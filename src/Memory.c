#include "Memory.h"

static int pageSize = 4096;
static int pageCount = 16; // Minumum number of pages
static bool initialized = false;

struct BoundryTag* freePages[MAXEXP];
int completePages[MAXEXP];

static inline int GetExp(unsigned int size)
{
	if(size < (1<<MINEXP))
		return -1;
	int shift;
	for(shift = MINEXP; shift < MAXEXP; shift++)
	{
		if((1<<shift) > size)
			break;
	}
	return shift - 1; // returns shift-1 aka (1<<(shift-1)) bytes for the passed size
}

void* MemoryAlloc(int pages)
{
	return 0; // TODO: Actually allocate some memory.
}

int MemoryFree(void* ptr, int pages)
{
	return 0; // TODO: Actually free some memory.  lql
}

static struct BoundryTag* AllocateNewTag(unsigned int size)
{
	unsigned int usage = size + sizeof(struct BoundryTag); // Required space
	unsigned int pages = usage / pageSize;
	if((usage % pageSize) != 0)
		pages++;
	if(pages < pageCount) // keeps pages >= the minimum size
		pages = pageCount;

	struct BoundryTag* tag = (struct BoundryTag*)MemoryAlloc(pages);

	if(tag == 0)
		return 0; // We're out of memory!
	tag->magic = MALLOC_MAGIC;
	tag->size  = size;
	tag->realSize = pages * pageSize;
	tag->index = -1;
	tag->next = 0;
	tag->prev = 0;
	tag->splitRight = 0;
	tag->splitLeft = 0;
	return tag;
}

static inline void RemoveTag(struct BoundryTag* tag)
{
	// lets move some nodes!
	if(freePages[tag->index] == tag)
		freePages[tag->index] = tag->next;
	if(tag->prev != 0)
		tag->prev->next = tag->next;
	if(tag->next != 0)
		tag->next->prev = tag->prev;
	tag->next = 0;
	tag->prev = 0;
	tag->index = -1;
}

static inline void InsertTag(struct BoundryTag* tag, int index)
{
	int realIndex;
	if(index < 0)
	{
		realIndex = GetExp(tag->realSize - sizeof(struct BoundryTag));
		if(realIndex < MINEXP)
			realIndex = MINEXP;
	}
	else
		realIndex = index;
	
	tag->index = realIndex;

	if(freePages[realIndex] != 0)
	{
		freePages[realIndex]->prev = tag;
		tag->next = freePages[realIndex];
	}
	freePages[realIndex] = tag;
}

static inline struct BoundryTag* SplitTag(struct BoundryTag* tag)
{
	unsigned int remainder = tag->realSize - sizeof(struct BoundryTag) - tag->size;
	struct BoundryTag* newTag = (struct BoundryTag*)((unsigned int)tag + sizeof(struct BoundryTag) + tag->size);
	newTag->magic = MALLOC_MAGIC;
	newTag->realSize = remainder;
	newTag->next = 0;
	newTag->prev = 0;
	newTag->splitLeft = tag;
	newTag->splitRight = tag->splitRight;
	if(newTag->splitRight != 0)
		newTag->splitRight->splitLeft = newTag;
	tag->splitRight = newTag;
	tag->realSize -= newTag->realSize;
	InsertTag(newTag, -1);
	return newTag;
}

void* malloc(size_t size)
{
	if(!initialized)
	{
		for(int i=0; i < MAXEXP; i++)
		{
			freePages[i] = 0; // Zero out data
			completePages[i] = 0;
		}
		initialized = true;
	}

	int index = GetExp(size);
	if(index < MINEXP)
		index = MINEXP;

	struct BoundryTag* tag;
	for(tag = freePages[index]; tag != 0; tag = tag->next)
		if((tag->realSize - sizeof(struct BoundryTag)) >= (size + sizeof(struct BoundryTag)))
			break;
	// No page found
	if(tag == 0)
	{
		if((tag = AllocateNewTag(size)) == 0)
			return 0;
		index = GetExp(tag->realSize - sizeof(struct BoundryTag));
	}
	else
	{
		RemoveTag(tag);
		if((tag->splitLeft == 0) && (tag->splitRight == 0))
			completePages[index]--;
	}
	tag->size = size;
	unsigned int remainder = tag->realSize - size - sizeof(struct BoundryTag) * 2; // Support a new tag + remainder
	if((int)(remainder) > 0)
	{
		int childIndex = GetExp(remainder);
		if(childIndex >= 0)
		{
			struct BoundryTag* newTag = SplitTag(tag);
			newTag = newTag; // Silly compiler wanting to warn abount unused variables :)
		}
	}
	void* ptr = (void*)((unsigned int)tag + sizeof(struct BoundryTag));
	return ptr;
}

void free(void* ptr)
{
	if(ptr == 0)
		return;
	
	struct BoundryTag* tag = (struct BoundryTag*)((unsigned int)ptr - sizeof(struct BoundryTag));
}
