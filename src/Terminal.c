#include "Terminal.h"

struct Terminal* CreateTerminal(uint8_t id)
{
	// How would I do this without losing all my terminals in the array after InitTerminals is finished?
	struct Terminal term;
	term.id = id;
	term.row = 0;
	term.column = 0;
	term.color = NewColorShceme(COLOR_LIGHT_GREY, COLOR_BLACK);
	term.buffer = (uint16_t*) VGA_ADDRESS; // VGA text mode buffer output device
	for (size_t y = 0; y < VGA_HEIGHT; y++)
		for(size_t x = 0; x < VGA_WIDTH; x++)
		{
			const size_t i = y * VGA_WIDTH + x;
			term.buffer[i] = Colorfy(' ', term.color);
		}
	return &term;
}

void InitTerminals()
{
	for(int i = 0; i < MAX_TERMINALS; i++)
		terminalList[i] = CreateTerminal(i);
	currentTerm = terminalList;
}

void WriteCharAt(char c, uint8_t color, size_t x, size_t y)
{
	const size_t i = y * VGA_WIDTH + x;
	currentTerm->buffer[i] = Colorfy(c, color);
}

void WriteChar(char c)
{
	WriteCharAt(c, currentTerm->color, currentTerm->column, currentTerm->row);
	if(++currentTerm->column == VGA_WIDTH)
	{
		currentTerm->column = 0;
		if(++currentTerm->row == VGA_HEIGHT)
			currentTerm->row = 0;
	}
}

void WriteString(const char* message)
{
	size_t length = strlen(message);
	for(size_t i = 0; i < length; i++)
		WriteChar(message[i]);
}