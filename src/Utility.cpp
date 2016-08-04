#include "Utility.h"

// Color Stuffs //
uint8_t NewColorShceme(enum Color fg, enum Color bg) {
	return fg | bg << 4;
}

uint16_t Colorfy(char c, uint8_t color) {
	uint16_t c2 = c;
	uint16_t color2 = color;
	return c2 | color2 << 8;
}
// End Color Stuffs //

// strlen is in C standard but we live outside the standard so we write our own.
size_t strlen(const char* str) {
	size_t size = 0;
	while(str[size] != 0)
		size++;
	return size;
}
