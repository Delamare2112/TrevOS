#include "Terminal.hpp"

Terminal Terminal::terminals[2];
Terminal* Terminal::currentTerminal = &Terminal::terminals[0];
uint16_t*const Terminal::VGA_Buffer = (uint16_t*) VGA_ADDRESS;

Terminal* Terminal::GetCurrentTerminal() { return currentTerminal; }

Terminal::Terminal() :
	row(0),
	column(0),
	color(Color::NewColorShceme(Color::Color::white, Color::Color::black))
{
	// Clear();
}

void Terminal::Clear()
{
	for (size_t y = 0; y < VGA_HEIGHT; y++)
		for(size_t x = 0; x < VGA_WIDTH; x++)
		{
			WriteCharAt(' ', x, y);
		}
}

void Terminal::ClearScreen()
{
	for (size_t y = 0; y < VGA_HEIGHT; y++)
		for(size_t x = 0; x < VGA_WIDTH; x++)
		{
			VGA_Buffer[y * VGA_WIDTH + x] = Color::Colorfy(' ', Color::NewColorShceme(Color::Color::black, Color::Color::black));
		}
}

void Terminal::ReDraw()
{
	for (size_t y = 0; y < VGA_HEIGHT; y++)
		for(size_t x = 0; x < VGA_WIDTH; x++)
		{
			const size_t loc = y * VGA_WIDTH + x;
			VGA_Buffer[loc] = buffer[loc];
		}
}

void Terminal::ChangeColor(Color::Color fg, Color::Color bg)
{
	color = Color::NewColorShceme(fg, bg);
}

void Terminal::WriteCharAt(char c, size_t x, size_t y)
{
	const uint16_t data = Color::Colorfy(c, color);
	const size_t loc = y * VGA_WIDTH + x;
	buffer[loc] = data;
	// if(this == currentTerminal)
		VGA_Buffer[loc] = data;
}

void Terminal::WriteChar(char c)
{
	if(c == '\n')
	{
		column = 0;
		if(++row == VGA_HEIGHT)
			row = 0;
	}
	else
	{
		WriteCharAt(c, column, row);
		if(++column == VGA_WIDTH)
		{
			column = 0;
			if(++row == VGA_HEIGHT)
				row = 0;
		}
	}
}

void Terminal::WriteString(const char* message)
{
	size_t length = strlen(message);
	for(size_t i = 0; i < length; i++)
		WriteChar(message[i]);
}
