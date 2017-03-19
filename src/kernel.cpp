#include "kernel.hpp"
#include "Utility.hpp"

void StartKernel()
{
	// Terminal& t = *Terminal::GetCurrentTerminal();
	// t.Terminal();
	// Terminal::ClearScreen();
	// ((uint16_t*)VGA_ADDRESS)[0 * VGA_WIDTH + 0] = Color::Colorfy('A', Color::NewColorShceme(Color::Color::white, Color::Color::black));
	// Terminal::GetCurrentTerminal()->WriteCharAt('A', 0, 0);
	// Terminal::GetCurrentTerminal()->WriteString("Hello C++ World");

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
	Terminal::GetCurrentTerminal()->WriteString("\nHow did I get here?\n");

}

void Panic()
{
	Terminal::GetCurrentTerminal()->ChangeColor(Color::Color::red, Color::Color::black);
	Terminal::GetCurrentTerminal()->WriteString("\nOh Shit! It might be a good idea to kill your system...");
	for(;;)
		asm("hlt");
}
