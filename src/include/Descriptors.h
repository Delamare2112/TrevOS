#pragma once
#include <stdint.h>

typedef struct
{
	unsigned int a, b;
} __attribute__((packed)) GateDescriptor;

typedef struct
{
	uint16_t size;
	uint32_t address;
} __attribute__((packed)) DescriptorPointer;

DescriptorPointer IDT_Descriptor;
GateDescriptor IDT_Table[256];

DescriptorPointer GDT_Descriptor;
uint64_t GDT_Table[256]; // TODO: should be a DescriptorPointer