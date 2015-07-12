#include "GDT.h"

uint64_t CreateDescriptor(uint32_t base, uint32_t limit, uint16_t flag)
{
	uint64_t descriptor;

	descriptor = limit & 0x000F0000; // 19:16
	descriptor |= (flag << 8) & 0x00F0FF00; // type, p, dpl, s, g, d/b, l, avl
	descriptor |= (base >> 16) & 0x000000FF; // 23:16
	descriptor |= base & 0xFF000000; // 31:24

	descriptor <<= 32; // allows for low part of segment

	// create the low segment
	descriptor |= base << 16; // base 15:0
	descriptor |= limit & 0x0000FFFF; // limit 15:0
	return descriptor;
}

void InitializeGDT()
{
	GDT_Table[0] = CreateDescriptor(0,0,0);
	GDT_Table[1] = CreateDescriptor(0, 0xffffffff, GDT_CODE_PL0);
	GDT_Table[2] = CreateDescriptor(0, 0xffffffff, GDT_DATA_PL0);
	GDT_Descriptor.size = (256*8);
	GDT_Descriptor.address = (unsigned int)GDT_Table;
	asm volatile("lgdt %0"::"m" (GDT_Descriptor));
	ReloadSegments();
}