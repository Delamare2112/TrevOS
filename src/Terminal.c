void CreateTerminal()
{
	term.row = 0;
	term.column = 0;
	term.color = NewColorShceme(COLOR_LIGHT_GREY, COLOR_BLACK);
	term.buffer = (uint16_t*) VGA_ADDRESS; // VGA text mode buffer output device
	for (size_t y = 0; y < VGA_HEIGHT; y++)
		for(size_t x = 0; x < VGA_WIDTH; x++)
		{
			const size_t i = y * VGA_WIDTH + x;
			term.buffer[i] = Colorfy(' ', term.color);
		}
}

void WriteCharAt(char c, uint8_t color, size_t x, size_t y)
{
	const size_t i = y * VGA_WIDTH + x;
	term.buffer[i] = Colorfy(c, color);
}

void WriteChar(char c)
{
	WriteCharAt(c, term.color, term.column, term.row);
	if(++term.column == VGA_WIDTH)
	{
		term.column = 0;
		if(++term.row == VGA_HEIGHT)
			term.row = 0;
	}
}

void WriteString(const char* message)
{
	size_t length = strlen(message);
	for(size_t i = 0; i < length; i++)
		WriteChar(message[i]);
}
