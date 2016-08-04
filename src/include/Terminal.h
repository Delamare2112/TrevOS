// Terminal.h
#pragma once
#include "Utility.h"
#include "config.h"

class Terminal {
private:
	uint8_t id;
	size_t row;
	size_t column;
	uint8_t color;
	uint16_t* buffer;

public:
	Terminal(size_t row = 0, size_t column = 0, uint8_t color = NewColorShceme(COLOR_LIGHT_GREY, COLOR_BLACK), uint16_t* buffer = (uint16_t*) VGA_ADDRESS);

	void WriteCharAt(char c, uint8_t color, size_t x, size_t y);
	void WriteChar(char c);
	void WriteString(const char* message);
};
