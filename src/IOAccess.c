#include "IOAccess.h"

void OutByte(unsigned short port, unsigned char val) // Sends an unsigned char value to a location
{
	asm volatile ("outb %1, %0" : : "dN" (port), "a" (val));
}

unsigned char InByte(unsigned short port)
{
	unsigned char ret;
	asm volatile ("inb %1, %0" : "=a" (ret) : "dN" (port));
	return ret;
}

void IOWait() // Wait for an I/O operation to complete
{
	asm volatile(	"jmp 1f\n\t"
					"1:jmp 2f\n\t"
					"2:");
}
