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
	Terminal(unit8_t id, size_t row, size_t column, unit8_t color, unit16_t* buffer);

	void WriteCharAt(char c);
	void WriteCharAt(char c, uint8_t color, size_t x, size_t y);
	void WriteChar(char c);
	void WriteString(const char* message);
};
