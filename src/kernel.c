#if defined(__linux__)
#error "Why you no cross-compile?! You want to hurt?!"
#endif

#if !defined(__i386__)
#error "you might want to try a i386-elf compiler"
#endif

#include <stdbool.h> // booleve it or not C doesn't have bools by deafult!
#include <stddef.h>
#include <stdint.h>

#include "config.h"
#include "Terminal.h"
#include "Memory.h"
#include "InterruptHandler.h"

void Panic();

void StartKernel()
{
	CreateTerminal();
	WriteString("Hello World! This is a test!\n\n");
	MakeInterruptsWork();
	PICRemap(0x20, 0x28);
	MaskIRQ(0xFF);
	asm volatile("int $10");
	Panic();
}

void Panic()
{
	ChangeColor(COLOR_RED, COLOR_BLACK);
	WriteString("\nOh Shit! It might be a good idea to kill your system...");
	for(;;)
		asm("hlt");
}
