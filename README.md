# TrevOS
The Real OS, The Best OS.

Are you tired of using an operating system that people know by name?  Use this instead!
TrevOS doesn't pretend that it's better than other any other OS.  It proves that it's faster by running faster than Karl Matthews!  And he just got a new walker!

## Building TrevOS

Assemble: `i686-elf-as boot.s -o boot.o`

Compile: `i686-elf-gcc -c kernel.c -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra`

Link: `i686-elf-gcc -T linker.ld -o TrevOS.elf -ffreestanding -O2 -nostdlib boot.o kernel.o -lgcc`

QEMU: `qemu-system-i386 -kernel TrevOS.elf`

ISO: `cp TrevOS.elf grubISO/boot/ && grub-mkrescue -o TrevOS.iso grubISO/`

## Screenshot
https://drive.google.com/open?id=0B6bzzVlpLPCbVGpwWjJJdmVjNW8&authuser=0
