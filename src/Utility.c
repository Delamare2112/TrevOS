// Utility.c

#include "Utility.h"
#include "Terminal.h"
#include "Memory.h"

// Color Stuffs //
uint8_t NewColorShceme(enum Color fg, enum Color bg)
{
	return fg | bg << 4;
}

uint16_t Colorfy(char c, uint8_t color)
{
	uint16_t c2 = c;
	uint16_t color2 = color;
	return c2 | color2 << 8;
}
// End Color Stuffs //

// strlen is in C standard but we live outside the standard so we write our own.
size_t strlen(const char* str)
{
	size_t size = 0;
	while(str[size] != 0)
		size++;
	return size;
}

char* itoawb(int val, int base)
{
	// char buff[32] = {0};
	char* buff = malloc(sizeof(char) * 32);
	int i = 30;
	for(;val && i; --i, val /= base)
	{
		buff[i] = "0123456789ABCDEF"[val % base];
	}
	int j = 0;
	i++;
	for(; i < 31; i++, j++)
		buff[j] = buff[i];
	buff[++j] = 0;
	return buff;
}

char* itoa(int val)
{
	return itoawb(val, 10);
}
