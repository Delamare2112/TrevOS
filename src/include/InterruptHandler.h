#pragma once

#include "Terminal.h"
#include "IOAccess.h"
#include "defines.h"
#include "Descriptors.h"

#define MASTER_DATA 0x21
#define SLAVE_DATA 0xA1

#define MASTER 0x20
#define SLAVE 0xA0
#define EOI 0x20

#define ICW1_INIT 0x10
#define ICW1_EDGE 0x08
#define ICW1_SINGLE 0x02
#define ICW1_ICW4 0x01

#define ICW4_SFNM 0x10
#define ICW4_BUFFER 0x08
#define ICW4_MASTER 0x04
#define ICW4_AROI 0x02
#define ICW4_8086 0x01

#define INT_0 0x8E00
#define INT_3 0xEE00

extern void InterruptWrapper0();

void InterruptHandler();
void MakeInterruptsWork();
void PICRemap(int offsetM, int offsetS);
void MaskIRQ(unsigned char irq);
void UnmaskIRQ(unsigned char irq);
void AddInterrupt(int number, void (*handler)(), uint dpl);
void AddInterrupts();
