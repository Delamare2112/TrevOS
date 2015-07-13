#include "InterruptHandler.h"

int counterOfThings = 0;

void SayHello()
{
	WriteString("\nHello!\n");
}

void InterruptHandler(CPU_State s, int vector)
{
	s.eax++;s.eax--; // remove warning about s
	WriteString("\nNumber: ");
	WriteString(itoa(vector));

	if(vector == 0x21)
		InByte(0x60); // If I don't take the byte, keyboard will stop working.

	if(vector >= 20)
		OutByte(SLAVE, 0x20);
	OutByte(MASTER, 0x20);

	WriteString(" Interrupt Handled (");
	WriteString(itoa(++counterOfThings));
	WriteString(")\n");
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

#define GETBIT(N,P) ((N >> P) & 1)

void MakeInterruptsWork()
{
	AddInterrupts();
	IDT_Descriptor.size = (256*8)-1;
	IDT_Descriptor.address = (unsigned int)IDT_Table;
	asm volatile("lidt %0"::"m" (IDT_Descriptor));
}

void AddIntterrupt(int number, void (*handler)())
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

void AddInterrupts()
{
	AddIntterrupt(0,InterruptWrapper0);
	AddIntterrupt(1,InterruptWrapper1);
	AddIntterrupt(2,InterruptWrapper2);
	AddIntterrupt(3,InterruptWrapper3);
	AddIntterrupt(4,InterruptWrapper4);
	AddIntterrupt(5,InterruptWrapper5);
	AddIntterrupt(6,InterruptWrapper6);
	AddIntterrupt(7,InterruptWrapper7);
	AddIntterrupt(8,InterruptWrapper8);
	AddIntterrupt(9,InterruptWrapper9);
	AddIntterrupt(10,InterruptWrapper10);
	AddIntterrupt(11,InterruptWrapper11);
	AddIntterrupt(12,InterruptWrapper12);
	AddIntterrupt(13,InterruptWrapper13);
	AddIntterrupt(14,InterruptWrapper14);
	AddIntterrupt(15,InterruptWrapper15);
	AddIntterrupt(16,InterruptWrapper16);
	AddIntterrupt(17,InterruptWrapper17);
	AddIntterrupt(18,InterruptWrapper18);
	AddIntterrupt(19,InterruptWrapper19);
	AddIntterrupt(20,InterruptWrapper20);
	AddIntterrupt(21,InterruptWrapper21);
	AddIntterrupt(22,InterruptWrapper22);
	AddIntterrupt(23,InterruptWrapper23);
	AddIntterrupt(24,InterruptWrapper24);
	AddIntterrupt(25,InterruptWrapper25);
	AddIntterrupt(26,InterruptWrapper26);
	AddIntterrupt(27,InterruptWrapper27);
	AddIntterrupt(28,InterruptWrapper28);
	AddIntterrupt(29,InterruptWrapper29);
	AddIntterrupt(30,InterruptWrapper30);
	AddIntterrupt(31,InterruptWrapper31);
	AddIntterrupt(32,InterruptWrapper32);
	AddIntterrupt(33,InterruptWrapper33);
	AddIntterrupt(34,InterruptWrapper34);
	AddIntterrupt(35,InterruptWrapper35);
	AddIntterrupt(36,InterruptWrapper36);
	AddIntterrupt(37,InterruptWrapper37);
	AddIntterrupt(38,InterruptWrapper38);
	AddIntterrupt(39,InterruptWrapper39);
	AddIntterrupt(39,InterruptWrapper39);
	AddIntterrupt(40,InterruptWrapper40);
	AddIntterrupt(41,InterruptWrapper41);
	AddIntterrupt(42,InterruptWrapper42);
	AddIntterrupt(43,InterruptWrapper43);
	AddIntterrupt(44,InterruptWrapper44);
	AddIntterrupt(45,InterruptWrapper45);
	AddIntterrupt(46,InterruptWrapper46);
	AddIntterrupt(47,InterruptWrapper47);
	AddIntterrupt(48,InterruptWrapper48);
	AddIntterrupt(49,InterruptWrapper49);
	AddIntterrupt(50,InterruptWrapper50);
	AddIntterrupt(51,InterruptWrapper51);
	AddIntterrupt(52,InterruptWrapper52);
	AddIntterrupt(53,InterruptWrapper53);
	AddIntterrupt(54,InterruptWrapper54);
	AddIntterrupt(55,InterruptWrapper55);
	AddIntterrupt(56,InterruptWrapper56);
	AddIntterrupt(57,InterruptWrapper57);
	AddIntterrupt(58,InterruptWrapper58);
	AddIntterrupt(59,InterruptWrapper59);
	AddIntterrupt(60,InterruptWrapper60);
	AddIntterrupt(61,InterruptWrapper61);
	AddIntterrupt(62,InterruptWrapper62);
	AddIntterrupt(63,InterruptWrapper63);
	AddIntterrupt(64,InterruptWrapper64);
	AddIntterrupt(65,InterruptWrapper65);
	AddIntterrupt(66,InterruptWrapper66);
	AddIntterrupt(67,InterruptWrapper67);
	AddIntterrupt(68,InterruptWrapper68);
	AddIntterrupt(69,InterruptWrapper69);
	AddIntterrupt(70,InterruptWrapper70);
	AddIntterrupt(71,InterruptWrapper71);
	AddIntterrupt(72,InterruptWrapper72);
	AddIntterrupt(73,InterruptWrapper73);
	AddIntterrupt(74,InterruptWrapper74);
	AddIntterrupt(75,InterruptWrapper75);
	AddIntterrupt(76,InterruptWrapper76);
	AddIntterrupt(77,InterruptWrapper77);
	AddIntterrupt(78,InterruptWrapper78);
	AddIntterrupt(79,InterruptWrapper79);
	AddIntterrupt(80,InterruptWrapper80);
	AddIntterrupt(81,InterruptWrapper81);
	AddIntterrupt(82,InterruptWrapper82);
	AddIntterrupt(83,InterruptWrapper83);
	AddIntterrupt(84,InterruptWrapper84);
	AddIntterrupt(85,InterruptWrapper85);
	AddIntterrupt(86,InterruptWrapper86);
	AddIntterrupt(87,InterruptWrapper87);
	AddIntterrupt(88,InterruptWrapper88);
	AddIntterrupt(89,InterruptWrapper89);
	AddIntterrupt(90,InterruptWrapper90);
	AddIntterrupt(91,InterruptWrapper91);
	AddIntterrupt(92,InterruptWrapper92);
	AddIntterrupt(93,InterruptWrapper93);
	AddIntterrupt(94,InterruptWrapper94);
	AddIntterrupt(95,InterruptWrapper95);
	AddIntterrupt(96,InterruptWrapper96);
	AddIntterrupt(97,InterruptWrapper97);
	AddIntterrupt(98,InterruptWrapper98);
	AddIntterrupt(99,InterruptWrapper99);
	AddIntterrupt(100,InterruptWrapper100);
	AddIntterrupt(101,InterruptWrapper101);
	AddIntterrupt(102,InterruptWrapper102);
	AddIntterrupt(103,InterruptWrapper103);
	AddIntterrupt(104,InterruptWrapper104);
	AddIntterrupt(105,InterruptWrapper105);
	AddIntterrupt(106,InterruptWrapper106);
	AddIntterrupt(107,InterruptWrapper107);
	AddIntterrupt(108,InterruptWrapper108);
	AddIntterrupt(109,InterruptWrapper109);
	AddIntterrupt(110,InterruptWrapper110);
	AddIntterrupt(111,InterruptWrapper111);
	AddIntterrupt(112,InterruptWrapper112);
	AddIntterrupt(113,InterruptWrapper113);
	AddIntterrupt(114,InterruptWrapper114);
	AddIntterrupt(115,InterruptWrapper115);
	AddIntterrupt(116,InterruptWrapper116);
	AddIntterrupt(117,InterruptWrapper117);
	AddIntterrupt(118,InterruptWrapper118);
	AddIntterrupt(119,InterruptWrapper119);
	AddIntterrupt(120,InterruptWrapper120);
	AddIntterrupt(121,InterruptWrapper121);
	AddIntterrupt(122,InterruptWrapper122);
	AddIntterrupt(123,InterruptWrapper123);
	AddIntterrupt(124,InterruptWrapper124);
	AddIntterrupt(125,InterruptWrapper125);
	AddIntterrupt(126,InterruptWrapper126);
	AddIntterrupt(127,InterruptWrapper127);
	AddIntterrupt(128,InterruptWrapper128);
	AddIntterrupt(129,InterruptWrapper129);
	AddIntterrupt(130,InterruptWrapper130);
	AddIntterrupt(131,InterruptWrapper131);
	AddIntterrupt(132,InterruptWrapper132);
	AddIntterrupt(133,InterruptWrapper133);
	AddIntterrupt(134,InterruptWrapper134);
	AddIntterrupt(135,InterruptWrapper135);
	AddIntterrupt(136,InterruptWrapper136);
	AddIntterrupt(137,InterruptWrapper137);
	AddIntterrupt(138,InterruptWrapper138);
	AddIntterrupt(139,InterruptWrapper139);
	AddIntterrupt(140,InterruptWrapper140);
	AddIntterrupt(141,InterruptWrapper141);
	AddIntterrupt(142,InterruptWrapper142);
	AddIntterrupt(143,InterruptWrapper143);
	AddIntterrupt(144,InterruptWrapper144);
	AddIntterrupt(145,InterruptWrapper145);
	AddIntterrupt(146,InterruptWrapper146);
	AddIntterrupt(147,InterruptWrapper147);
	AddIntterrupt(148,InterruptWrapper148);
	AddIntterrupt(149,InterruptWrapper149);
	AddIntterrupt(150,InterruptWrapper150);
	AddIntterrupt(151,InterruptWrapper151);
	AddIntterrupt(152,InterruptWrapper152);
	AddIntterrupt(153,InterruptWrapper153);
	AddIntterrupt(154,InterruptWrapper154);
	AddIntterrupt(155,InterruptWrapper155);
	AddIntterrupt(156,InterruptWrapper156);
	AddIntterrupt(157,InterruptWrapper157);
	AddIntterrupt(158,InterruptWrapper158);
	AddIntterrupt(159,InterruptWrapper159);
	AddIntterrupt(160,InterruptWrapper160);
	AddIntterrupt(161,InterruptWrapper161);
	AddIntterrupt(162,InterruptWrapper162);
	AddIntterrupt(163,InterruptWrapper163);
	AddIntterrupt(164,InterruptWrapper164);
	AddIntterrupt(165,InterruptWrapper165);
	AddIntterrupt(166,InterruptWrapper166);
	AddIntterrupt(167,InterruptWrapper167);
	AddIntterrupt(168,InterruptWrapper168);
	AddIntterrupt(169,InterruptWrapper169);
	AddIntterrupt(170,InterruptWrapper170);
	AddIntterrupt(171,InterruptWrapper171);
	AddIntterrupt(172,InterruptWrapper172);
	AddIntterrupt(173,InterruptWrapper173);
	AddIntterrupt(174,InterruptWrapper174);
	AddIntterrupt(175,InterruptWrapper175);
	AddIntterrupt(176,InterruptWrapper176);
	AddIntterrupt(177,InterruptWrapper177);
	AddIntterrupt(178,InterruptWrapper178);
	AddIntterrupt(179,InterruptWrapper179);
	AddIntterrupt(180,InterruptWrapper180);
	AddIntterrupt(181,InterruptWrapper181);
	AddIntterrupt(182,InterruptWrapper182);
	AddIntterrupt(183,InterruptWrapper183);
	AddIntterrupt(184,InterruptWrapper184);
	AddIntterrupt(185,InterruptWrapper185);
	AddIntterrupt(186,InterruptWrapper186);
	AddIntterrupt(187,InterruptWrapper187);
	AddIntterrupt(188,InterruptWrapper188);
	AddIntterrupt(189,InterruptWrapper189);
	AddIntterrupt(190,InterruptWrapper190);
	AddIntterrupt(191,InterruptWrapper191);
	AddIntterrupt(192,InterruptWrapper192);
	AddIntterrupt(193,InterruptWrapper193);
	AddIntterrupt(194,InterruptWrapper194);
	AddIntterrupt(195,InterruptWrapper195);
	AddIntterrupt(196,InterruptWrapper196);
	AddIntterrupt(197,InterruptWrapper197);
	AddIntterrupt(198,InterruptWrapper198);
	AddIntterrupt(199,InterruptWrapper199);
	AddIntterrupt(200,InterruptWrapper200);
	AddIntterrupt(201,InterruptWrapper201);
	AddIntterrupt(202,InterruptWrapper202);
	AddIntterrupt(203,InterruptWrapper203);
	AddIntterrupt(204,InterruptWrapper204);
	AddIntterrupt(205,InterruptWrapper205);
	AddIntterrupt(206,InterruptWrapper206);
	AddIntterrupt(207,InterruptWrapper207);
	AddIntterrupt(208,InterruptWrapper208);
	AddIntterrupt(209,InterruptWrapper209);
	AddIntterrupt(210,InterruptWrapper210);
	AddIntterrupt(211,InterruptWrapper211);
	AddIntterrupt(212,InterruptWrapper212);
	AddIntterrupt(213,InterruptWrapper213);
	AddIntterrupt(214,InterruptWrapper214);
	AddIntterrupt(215,InterruptWrapper215);
	AddIntterrupt(216,InterruptWrapper216);
	AddIntterrupt(217,InterruptWrapper217);
	AddIntterrupt(218,InterruptWrapper218);
	AddIntterrupt(219,InterruptWrapper219);
	AddIntterrupt(220,InterruptWrapper220);
	AddIntterrupt(223,InterruptWrapper223);
	AddIntterrupt(224,InterruptWrapper224);
	AddIntterrupt(225,InterruptWrapper225);
	AddIntterrupt(226,InterruptWrapper226);
	AddIntterrupt(227,InterruptWrapper227);
	AddIntterrupt(228,InterruptWrapper228);
	AddIntterrupt(229,InterruptWrapper229);
	AddIntterrupt(230,InterruptWrapper230);
	AddIntterrupt(231,InterruptWrapper231);
	AddIntterrupt(232,InterruptWrapper232);
	AddIntterrupt(233,InterruptWrapper233);
	AddIntterrupt(234,InterruptWrapper234);
	AddIntterrupt(235,InterruptWrapper235);
	AddIntterrupt(236,InterruptWrapper236);
	AddIntterrupt(237,InterruptWrapper237);
	AddIntterrupt(238,InterruptWrapper238);
	AddIntterrupt(239,InterruptWrapper239);
	AddIntterrupt(240,InterruptWrapper240);
	AddIntterrupt(241,InterruptWrapper241);
	AddIntterrupt(242,InterruptWrapper242);
	AddIntterrupt(243,InterruptWrapper243);
	AddIntterrupt(244,InterruptWrapper244);
	AddIntterrupt(245,InterruptWrapper245);
	AddIntterrupt(246,InterruptWrapper246);
	AddIntterrupt(247,InterruptWrapper247);
	AddIntterrupt(248,InterruptWrapper248);
	AddIntterrupt(249,InterruptWrapper249);
	AddIntterrupt(250,InterruptWrapper250);
	AddIntterrupt(251,InterruptWrapper251);
	AddIntterrupt(252,InterruptWrapper252);
	AddIntterrupt(253,InterruptWrapper253);
	AddIntterrupt(254,InterruptWrapper254);
	AddIntterrupt(255,InterruptWrapper255);
}
