#include "InterruptHandler.h"

int counterOfThings = 0;

void KeybaordHandler()
{
	char info = InByte(0x60);
	if(!(info & 0x80)) // 0x80 aka 10000000 is the released flag
		WriteChar("\0\0\0\01234567890-=\0\tqwertyuiop[]\n\0asdfghjkl;\'`\0\\zxcvbnm,./\0\0\0 \0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0-\05\0+\0\0\0\0\0\0\0\0\0\0"[info]);
}

void InterruptHandler(CPU_State s, int vector)
{
	s = s; // remove warning about s
	if(vector == 0x21)
		KeybaordHandler();
	else
	{
		WriteString("\nNumber: ");
		WriteString(itoa(vector));
		WriteString(" Interrupt Handled (");
		WriteString(itoa(++counterOfThings));
		WriteString(")\n");
	}
	if(vector >= 20)
		OutByte(SLAVE, 0x20);
	OutByte(MASTER, 0x20);

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

	OutByte(MASTER_DATA, 4);
	OutByte(SLAVE_DATA, 2);

	OutByte(MASTER_DATA, ICW4_8086);
	OutByte(SLAVE_DATA, ICW4_8086);

	// Restore data
	OutByte(MASTER_DATA, oldMasterData);
	OutByte(SLAVE_DATA, oldSlaveData);

	// enable keyboard
	OutByte(0x21, 0xfd);
	OutByte(0xa1, 0xff);
	asm("sti");
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

void MakeInterruptsWork()
{
	AddInterrupts(); // FIXME: Function never returns
	IDT_Descriptor.size = (256*8)-1;
	IDT_Descriptor.address = (unsigned int)IDT_Table;
	asm volatile("lidt %0"::"m" (IDT_Descriptor));
}

void MakeItWork() // FIXME: Shouldn't even be a function
{
	IDT_Descriptor.size = (256*8)-1;
	IDT_Descriptor.address = (unsigned int)IDT_Table;
	asm volatile("lidt %0"::"m" (IDT_Descriptor));
	PICRemap(0x20, 0x28);
	
	// Done setting up kernel!

	asm volatile("int $55");

	// If we return, AddInterrupts will attempt to return and kill the OS for some reason.
	// Because of this let's just sit here :P
	for(;;) asm("hlt");
}

void AddInterrupt(int number, void (*handler)())
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
	IDT_Table[number].b |= 0 << 13;
	IDT_Table[number].b |= d << 11;
	IDT_Table[number].b |= type << 8;

	IDT_Table[number].a = low;
	IDT_Table[number].a |= selector << 16;
}
