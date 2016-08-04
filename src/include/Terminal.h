// Terminal.h
#pragma once
#include "Utility.h"

class Terminal {
private:
	uint8_t id;
	size_t row;
	size_t column;
	uint8_t color;

	static const size_t VGA_WIDTH = 80;
	static const size_t VGA_HEIGHT = 25;

public:
	static uint16_t* const VGA_ADDRESS;

	Terminal(size_t row = 0, size_t column = 0, uint8_t color = NewColorShceme(COLOR_LIGHT_GREY, COLOR_BLACK));

	void WriteCharAt(char c, uint8_t color, size_t x, size_t y);
	void WriteChar(char c);
	void WriteString(const char* message);
};
