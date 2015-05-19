#include <stdbool.h> // booleve it or not C doesn't have bools by deafult!
#include <stddef.h>
#include <stdint.h>

#if defined(__linux__)
#error "Why you no cross-compile?! You want to hurt?!"
#endif

#if !defined(__i386__)
#error "you might want to try a ix86-elf compiler"
#endif

// strlen is in C standard but we live outside the standard so we write our own.
size_t strlen(const char* str)
{
	size_t size = 0;
	while(str[size] != 0)
		size++;
	return size;
}

// Color Stuffs //
enum Color
{
	COLOR_BLACK = 0,
	COLOR_BLUE = 1,
	COLOR_GREEN = 2,
	COLOR_CYAN = 3,
	COLOR_RED = 4,
	COLOR_MAGENTA = 5,
	COLOR_BROWN = 6,
	COLOR_LIGHT_GREY = 7,
	COLOR_DARK_GREY = 8,
	COLOR_LIGHT_BLUE = 9,
	COLOR_LIGHT_GREEN = 10,
	COLOR_LIGHT_CYAN = 11,
	COLOR_LIGHT_RED = 12,
	COLOR_LIGHT_MAGENTA = 13,
	COLOR_LIGHT_BROWN = 14,
	COLOR_WHITE = 15,
};

uint8_t ColorScheme(enum Color fg, enum Color bg)
{
	return fg | bg << 4;
}

uint16_t ColorChar(char c, uint8_t color)
{
	uint16_t c2 = c;
	uint16_t color2 = color;
	return c2 | color2 << 8;
}
// End Color Stuffs //

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;

size_t termRow, termColumn;
uint8_t termColor;
uint16_t* termBuffer;

void TerminalInitialization()
{
	termRow = 0;
	termColumn = 0;
	termColor = ColorScheme(COLOR_LIGHT_GREY, COLOR_BLACK);
	termBuffer = (uint16_t*) 0xB8000; // VGA text mode buffer output device
	for (size_t y = 0; y < VGA_HEIGHT; y++)
		for(size_t x = 0; x < VGA_WIDTH; x++)
		{
			const size_t i = y * VGA_WIDTH + x;
			termBuffer[i] = ColorChar(' ', termColor);
		}
}

void TerminalWriteCharAt(char c, uint8_t color, size_t x, size_t y)
{
	const size_t i = y * VGA_WIDTH + x;
	termBuffer[i] = ColorChar(c, color);
}

void TerminalWriteChar(char c)
{
	TerminalWriteCharAt(c, termColor, termColumn, termRow);
	if(++termColumn == VGA_WIDTH)
	{
		termColumn = 0;
		if(++termRow == VGA_HEIGHT)
			termRow = 0;
	}
}

void TerminalWriteString(const char* message)
{
	size_t length = strlen(message);
	for(size_t i = 0; i < length; i++)
		TerminalWriteChar(message[i]);
}

void StartKernel()
{
	TerminalInitialization();
	TerminalWriteString("Hello World!\n");
}
