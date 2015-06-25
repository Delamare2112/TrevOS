#include "InterruptHandler.h"

idtr IDTR;
Interrupt IDT[256];

void InterruptHandler()
{
	WriteString("Interrupt Handled");
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

void loadIDTR()
{
	IDTR.limit = 256*(sizeof(Interrupt)-1);
	IDTR.base = IDT;
	//WriteString("LoadIDTR");
	//WriteString(itoa(IDTR.base));
	// idtr* IDTRptr = &IDTR;
	// asm volatile("LIDT (%0) ": :"p" (&IDTR));
}

void AddIntterrupt(int number, void (*handler)(), uint dpl)
{
	ushort selector = 0x08;
	ushort settings;
	uint offset = (uint)handler;

	asm volatile("movw %%cs,%0" :"=g"(selector));

	if(dpl == 0)
		settings = INT_0;
	else if(dpl <= 3)
		settings = INT_3;

	IDT[number].lowOffset = (offset & 0xFFFF);
	IDT[number].selector = selector;
	IDT[number].settings = settings;
	IDT[number].highOffset = (offset >> 16);
}

void AddInterrupts()
{
	for(int i=0; i>31; i++)
	{
		AddInterrupt(i, InterruptHandler, 0);
	}
}
