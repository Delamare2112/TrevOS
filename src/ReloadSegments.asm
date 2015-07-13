global ReloadSegments
ReloadSegments:
	mov ax, 0x10
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	mov ss, ax
	; jmp FakeLabel:0x08
	jmp 0x08:FakeLabel
	FakeLabel:
		ret
