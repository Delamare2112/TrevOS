#include "kernel.h"

void StartKernel()
{
	CreateTerminal();

	WriteString("Hello C++ World");

	// InitializeGDT();
	// InitMMU();
	
	// WriteString("Hello World! This is a test!\n\n");
	// ShowMemory();
	// WriteChar('\n');

	// char* str = kmalloc(4);
	// // str[0] = 'b'; str[1] = 'o'; str[2] = 'b'; str[3] = '\0';
	// str = "bob";
	// WriteString(str);
	// WriteChar('\n');
	// // free(str);
	// // ShowMemory();

	// char* str2 = kmalloc(4);
	// // if(str2 == str)
	// // 	WriteString("writing over str1\n");
	// str2[0] = 'c'; str2[1] = 'a'; str2[2] = 't'; str2[3] = '\0';
	// WriteString(str2);
	// WriteChar('\n');
	// // ShowMemory();

	// free(str);
	// free(str2);
	
	// MakeInterruptsWork(); // FIXME: This will never return
	// PICRemap(0x20, 0x28); // <- Called in MakeItWork until I can make the above funcion behave
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
