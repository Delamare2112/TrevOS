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

// The fun of living outside of the C standard
size_t strlen(const char* str)
{
	size_t size = 0;
	while(str[size] != 0)
		size++;
	return size;
}

char* itoawb(int val, int base)
{
	char buff[32];
	buff[0] = '0'; buff[1] = '\0'; // Incase val is 0
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
	// free(buff);
	WriteString(""); // Needs to be called or bad things happen for some reason...
	return buff;
}

char* itoa(int val)
{
	return itoawb(val, 10);
}

void strcat(char* one, char* two)
{
	int oneLength = strlen(one);
	for(int i = oneLength; i < oneLength + strlen(two); i++)
	{
		one[i] = two[i - oneLength];
	}
}

void strReplaceAt(char* main, char* value, int length, int index)
{
	for(int i = 0; i < length; i++)
		main[index + i] = value[i];
}

// TODO: Make this work when key and value are not of the same length
void strReplace(char* main, char* key, char* value)
{
	int keyLen = strlen(key);
	int valueLen = strlen(value);
	for(int i=0; i < strlen(main); i++)
		for(int j = 0; j < keyLen && main[i+j] == key[j]; j++)
			if(j == keyLen)
				strReplaceAt(main, value, valueLen, i);
}
