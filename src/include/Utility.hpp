// Utility.h

#pragma once

#include <stdbool.h> // booleve it or not C doesn't have bools by deafult!
#include <stddef.h>
#include <stdint.h>

namespace Color
{
	enum class Color
	{
		black = 0,
		blue = 1,
		green = 2,
		cyan = 3,
		red = 4,
		magenta = 5,
		brown = 6,
		lightGrey = 7,
		darkGrey = 8,
		lightBlue = 9,
		lightGreen = 10,
		lightCyan = 11,
		lightRed = 12,
		lightMagenta = 13,
		lightBrown = 14,
		white = 15,
	};
	uint8_t NewColorShceme(Color fg, Color bg);
	uint16_t Colorfy(char c, uint8_t color);
}

size_t strlen(const char* str);
char* itoawb(int val, int base);
char* itoa(int val);
