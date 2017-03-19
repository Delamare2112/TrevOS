// Terminal.h
#pragma once
#include "Utility.hpp"
#include "config.hpp"

void CreateTerminal();

class Terminal
{
private:
	static uint16_t*const VGA_Buffer;
	static Terminal terminals[2]; // TODO: Make dynamic once we have dynamic memory
	static Terminal* currentTerminal;
	uint16_t buffer[VGA_WIDTH * VGA_HEIGHT];
	uint8_t id;
	size_t row, column;
	uint8_t color;

	void ReDraw();
public:
	Terminal();
	static Terminal* GetCurrentTerminal();
	static void ClearScreen();

	void ChangeColor(Color::Color fg, Color::Color bg);

	void Clear();
	void WriteChar(char c);
	void WriteCharAt(char c, size_t x, size_t y);
	void WriteString(const char* message);
};
