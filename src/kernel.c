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
#include "GDT.h"

void Panic();

void StartKernel()
{
	CreateTerminal();
	WriteString("Hello World! This is a test!\n\n");
	InitializeGDT();
	InitMMU();
	char* str = kmalloc(4);
	str[0] = 'b'; str[1] = 'o'; str[2] = 'b'; str[3] = '\0';
	WriteString(str);
	WriteChar('\n');

	char* str2 = kmalloc(4);
	str2[0] = 'c'; str2[1] = 'a'; str2[2] = 't'; str2[3] = '\0';
	WriteString(str2);
	WriteChar('\n');
	WriteString(str);
	
	MakeInterruptsWork(); // FIXME: This will never return
	PICRemap(0x20, 0x28); // <- Called in MakeItWork until I can make the above funcion behave
	for(;;) asm("hlt");
	WriteString("\nHow did I get here?\n");
}

void Panic()
{
	ChangeColor(COLOR_RED, COLOR_BLACK);
	WriteString("\nOh Shit! It might be a good idea to kill your system...");
	for(;;)
		asm("hlt");
}
