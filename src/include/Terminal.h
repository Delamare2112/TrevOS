// Terminal.h
#pragma once
#include "Utility.h"
#include "config.h"

struct Terminal
{
	uint8_t id;
	size_t row, column;
	uint8_t color;
	uint16_t* buffer;
};

extern struct Terminal term;

void CreateTerminal();

void ChangeColor(enum Color fg, enum Color bg);
void WriteCharAt(char c, uint8_t color, size_t x, size_t y);
void WriteChar(char c);
void WriteString(const char* message);
