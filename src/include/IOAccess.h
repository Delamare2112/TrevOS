// Useful  assembly I/O functions
#pragma once
#include <stdint.h>

typedef struct
{
	uint32_t edi;
	uint32_t esi;
	uint32_t ebp;
	uint32_t esp;
	uint32_t ebx;
	uint32_t edx;
	uint32_t ecx;
	uint32_t eax;
} CPU_State;

void OutByte(unsigned short port, unsigned char val);
unsigned char InByte(unsigned short port);
void IOWait();
