#include "InterruptHandler.h"

void InterruptHandler()
{
	WriteString("Interrupt Handled");
}

void PICSendEOI(unsigned char irq)
{
	if(irq >= 8)
		OutByte(PICS, PIC_EOI);
	OutByte(PICM, PIC_EOI);
}

void PICRemap(int offsetM, int offsetS)
{
	unsigned char aM = InByte(PICM_DATA); // masks
	unsigned char aS = InByte(PICS_DATA);

	OutByte(PICM, ICW1_INIT+ICW1_ICW4); // starts initialization in casecade mode
	IOWait();
	OutByte(PICS, ICW1_INIT+ICW1_ICW4);
	IOWait();
	OutByte(PICM_DATA, offsetM); // Master PIC vector offset
	IOWait();
	OutByte(PICS_DATA, offsetS); // Slave PIC vector offset
	IOWait();
	OutByte(PICM_DATA, 4); // Tell Master about Slave at IRQ2 (0000 0100)
	IOWait();
	OutByte(PICS_DATA, 2); // Tell Slave its cascade identity (0000 0010)
	IOWait();

	OutByte(PICM_DATA, ICW4_8086);
	IOWait();
	OutByte(PICS_DATA, ICW4_8086);
	IOWait();

	OutByte(PICM_DATA, aM);
	OutByte(PICS_DATA, aS);
}
