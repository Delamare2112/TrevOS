// Useful  assembly I/O functions
#pragma once

void OutByte(unsigned short port, unsigned char val);
unsigned char InByte(unsigned short port);
void IOWait();
