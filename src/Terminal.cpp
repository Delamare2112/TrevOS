#include "Terminal.h"

uint16_t* const Terminal::VGA_ADDRESS = (uint16_t*const)0xB8000;

Terminal::Terminal(size_t row, size_t column, enum Color fg, enum Color bg) {
	this->row = row;
	this->column = column;
	this->fg = fg;
	this->bg = bg;
	UpdateColorScheme();
	ClearScreen();
}

void Terminal::UpdateColorScheme() {
	colorShceme = fg | bg << 4;
}

void Terminal::ClearScreen() {
	for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for(size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t i = y * VGA_WIDTH + x;
			VGA_ADDRESS[i] = Colorfy(' ', colorShceme);
		}
	}
}

void Terminal::WriteCharAt(char c, uint8_t color, size_t x, size_t y) {
	const size_t i = y * VGA_WIDTH + x;
	VGA_ADDRESS[i] = Colorfy(c, color);
}

void Terminal::WriteChar(char c) {
	WriteCharAt(c, colorShceme, column, row);
	if(++column == VGA_WIDTH) {
		column = 0;
		if(++row == VGA_HEIGHT) {
			row = 0;
		}
	}
}

void Terminal::WriteString(const char* message) {
	size_t length = strlen(message);
	for(size_t i = 0; i < length; i++) {
		WriteChar(message[i]);
	}
}

extern "C"
void ForcePrintString(const char* message) {
	size_t length = strlen(message);
	uint8_t color = 7;
	for(size_t i = 0; i < length; i++) {
		Terminal::VGA_ADDRESS[i] = Terminal::Colorfy(message[i], color);
	}
}
