#include "Terminal.h"

Terminal::Terminal() {
	Terminal(0, 0, NewColorShceme(COLOR_LIGHT_GREY, COLOR_BLACK), (uint16_t*) VGA_ADDRESS);
}

Terminal::~Terminal() {}

Terminal::Terminal(size_t row, size_t column, unit8_t color, unit16_t* buffer) {
  this.row = row;
	this.column = column;
	this.color = color;
	this.buffer = buffer
	for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for(size_t x = 0; x < VGA_WIDTH; x++)
		{
			const size_t i = y * VGA_WIDTH + x;
			this.buffer[i] = Colorfy(' ', this.color);
		}
	}
}

void Terminal::WriteCharAt(char c, uint8_t color, size_t x, size_t y) {
  const size_t i = y * VGA_WIDTH + x;
	this.buffer[i] = Colorfy(c, color);
}

void Terminal::WriteChar(char c) {
  WriteCharAt(c, this.color, this.column, this.row);
	if(++this.column == VGA_WIDTH) {
		this.column = 0;
		if(++this.row == VGA_HEIGHT) {
			this.row = 0;
		}
	}
}

void Terminal::WriteString(const char* message) {
	size_t length = strlen(message);
	for(size_t i = 0; i < length; i++) {
		WriteChar(message[i]);
	}
}
