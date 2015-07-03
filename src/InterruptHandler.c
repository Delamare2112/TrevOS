#include "InterruptHandler.h"

void InterruptHandler()
{
	WriteString("Interrupt Handled");
	for(;;)
		asm("hlt");
}

void PICRemap(int pic1, int pic2)
{
	// Save the data currently in the data spaces
	unsigned char oldMasterData = InByte(MASTER_DATA);
	unsigned char oldSlaveData = InByte(SLAVE_DATA);

	// reset the chip (EOI: https://en.wikipedia.org/wiki/End_of_interrupt)
	OutByte(MASTER, EOI);

	// ICW1 control setup
	OutByte(MASTER, ICW1_INIT + ICW1_ICW4);
	OutByte(SLAVE, ICW1_INIT + ICW1_ICW4);

	OutByte(MASTER_DATA, pic1);
	OutByte(SLAVE_DATA, pic2);

	OutByte(MASTER_DATA, 0x04);
	OutByte(SLAVE_DATA, 0x02);

	OutByte(MASTER_DATA, ICW4_8086);
	OutByte(SLAVE_DATA, ICW4_8086);

	// Restore data
	OutByte(MASTER_DATA, oldMasterData);
	OutByte(SLAVE_DATA, oldSlaveData);
}

void MaskIRQ(unsigned char irq)
{
	if(irq == 0xFF)
	{
		OutByte(MASTER_DATA, 0xFF);
		OutByte(SLAVE_DATA, 0xFF);
	}
	else
	{
		irq = irq | (1<<irq);
		if(irq < 8)
			OutByte(MASTER_DATA, irq & 0xFF);
		else
			OutByte(SLAVE_DATA, irq >> 8);
	}
}

void UnmaskIRQ(unsigned char irq)
{
	if(irq == 0xFF)
	{
		OutByte(MASTER_DATA, 0x00);
		OutByte(SLAVE_DATA, 0x00);
	}
	else
	{
		irq = irq & (1<<irq);
		if(irq < 8)
			OutByte(MASTER_DATA, irq & 0xFF);
		else
			OutByte(SLAVE_DATA, irq >> 8);
	}
}

#define GETBIT(N,P) ((N >> P) & 1)

void MakeInterruptsWork()
{
	AddInterrupts();
	IDT_Descriptor.size = (256*8)-1;
	IDT_Descriptor.address = (unsigned int)IDT_Table;
	WriteString(itoawb(&IDT_Table, 16));
	asm volatile("lidt %0"::"m" (IDT_Descriptor));
}

void AddIntterrupt(int number, void (*handler)(), uint dpl)
{
	unsigned long address = (unsigned long)handler; // Because you can't bitwise operate an address(pointer)
	int high = address & 0xFFFF0000;
	int low = address & 0x0000FFFF;
	int p = 1; // selector present flag
	int selector = 1<<3; // segment selector for destination code segment
	int d = 1; // size of gate.  we have 32 bits so we put a one here.
	int type = 14;
	IDT_Table[number].b = high;
	IDT_Table[number].b |= p << 15;
	IDT_Table[number].b |= dpl << 13;
	IDT_Table[number].b |= d << 11;
	IDT_Table[number].b |= type << 8;

	IDT_Table[number].a = low;
	IDT_Table[number].a |= selector << 16;
}

void AddInterrupts()
{
	for(int i=0; i>31; i++)
	{
		AddInterrupt(i, InterruptWrapper0, 0);
	}
}
