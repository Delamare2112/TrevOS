; x86 crti.s
section .init
global hashlookup:function _init
_init:
	push ebp
	mov ebp, esp
	; gcc will nicely put the contents of crtbegin.o's .init section here.

section .fini
global hashlookup:function _fini
_fini:
	push ebp
	mov ebp, esp
	; gcc will nicely put the contents of crtbegin.o's .fini section here.
