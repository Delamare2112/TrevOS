#include "Terminal.h"

Terminal::Terminal() {
  this.row = 0;
	this.column = 0;
	this.color = NewColorShceme(COLOR_LIGHT_GREY, COLOR_BLACK);
	this.buffer = (uint16_t*) VGA_ADDRESS; // VGA text mode buffer output device
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
