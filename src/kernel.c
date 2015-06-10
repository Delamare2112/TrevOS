#if defined(__linux__)
#error "Why you no cross-compile?! You want to hurt?!"
#endif

#if !defined(__i386__)
#error "you might want to try a ix86-elf compiler"
#endif

#include <stdbool.h> // booleve it or not C doesn't have bools by deafult!
#include <stddef.h>
#include <stdint.h>

#include "config.h"
#include "Terminal.h"
#include "InterruptHandler.h"

void Panic();

void StartKernel()
{
	// PICRemap(500, 700);
	CreateTerminal();
	WriteString("Hello World! This is a test!");
	Panic();
	// asm("jmp do_test"); // This breaks everything.
}

void Panic()
{
	WriteString("\nChanging color");
	ChangeColor(COLOR_RED, COLOR_BLACK);
	WriteString("\nOh Shit! It might be a good idea to kill your system...");
	for(;;)
		asm("hlt");
}
