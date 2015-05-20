# TrevOS
The Real OS, The Best OS.  Well mainly just a fun educational adventure in CS!

Are you tired of using an operating system that people know by name?  Use this instead!
TrevOS doesn't pretend that it's better than other any other OS.  It proves that it's faster by running faster than Karl Matthews!  And he just got a new walker!

## Building TrevOS

You'll need a compiler that can create i686 elfs!  Additionally you need to modify line 16 of the Makefile to point the directory with the compiler.

`make`: This will compile, link, and produce the kernel bin/TrevOS.elf

`make emu`: This will test the kernel in bin/TrevOS.elf with qemu if you have it installed.

`make iso`: This is produce a bootable ISO at bin/TrevOS.iso if you have the grub-mkrescue command

`make fullemu`: Will boot bin/TrevOS.iso in qemu

`make clean`: Will remove all objects and elfs

## Screenshot
https://drive.google.com/open?id=0B6bzzVlpLPCbVGpwWjJJdmVjNW8&authuser=0
