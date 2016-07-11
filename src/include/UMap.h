#pragma once
// #include "Memory.h"
#include <stdio.h>

size_t SimpleHash(char* str)
{
#ifdef DEBUG_UMAP
	WriteString("\nDebug: sizeof(str) == ");
	WriteString(itoa(sizeof(str)));
#endif
	printf("\nDebug: sizeof(str) == %lu", sizeof(str));
	size_t value = 0;
	for(size_t i; i < sizeof(str); i++)
		value += str[i];
	return value;
}

// #define MAKE_UMAP(T)
typedef struct
{
	int* array;
	size_t capacity;
	size_t size;
} UMap;

UMap* CreateUMap(size_t capacity)
{
	// UMap* ret = kmalloc(sizeof(UMap));
	UMap* ret = malloc(sizeof(UMap));
	ret->capacity = capacity;
	const unsigned int bytes = sizeof(int) * capacity;
	// ret->array = kmalloc(bytes);
	ret->array = malloc(bytes);
	memset(ret->array, bytes, 0);
	return ret;
}

void SetUMapValue(UMap* this, char* key, int value)
{
	size_t index = SimpleHash(key) % this->capacity;
	int* arrayValuePtr = this->array[index];
	// TODO: Collision Prevention with LinkedList
	if(*arrayValuePtr != 0)
		// WriteString("Warning: Key in UMap already exists");
		printf("\nWarning: key in UMap already exists");
	else
		this->size++;
	*arrayValuePtr = value;
}

int GetFromUMap(UMap* this, char* key)
{
	return this->array[SimpleHash(key) % this->capacity];
}

