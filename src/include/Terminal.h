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

static struct Terminal* currentTerm;
static struct Terminal* terminalList[MAX_TERMINALS];

struct Terminal* CreateTerminal(uint8_t id);
void InitTerminals();

void WriteCharAt(char c, uint8_t color, size_t x, size_t y);
void WriteChar(char c);
void WriteString(const char* message);
