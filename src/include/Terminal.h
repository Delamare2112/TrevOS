// Terminal.h
#pragma once
#include "Utility.h"

class Terminal {
private:
	uint8_t id;
	size_t row;
	size_t column;
	enum Color fg;
	enum Color bg;

	static const size_t VGA_WIDTH = 80;
	static const size_t VGA_HEIGHT = 25;

	void ClearScreen();
	uint16_t Colorfy(char c, uint8_t color);

public:
	static uint16_t* const VGA_ADDRESS;

	Terminal(size_t row = 0, size_t column = 0, enum Color fg = COLOR_LIGHT_GREY, enum Color bg = COLOR_BLACK);

	uint8_t GetColorScheme();

	void WriteCharAt(char c, uint8_t color, size_t x, size_t y);
	void WriteChar(char c);
	void WriteString(const char* message);
};
