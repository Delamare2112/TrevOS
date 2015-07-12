global ReloadSegments
ReloadSegments:
	mov eax, 0x10
	mov ds, eax
	mov es, eax
	mov fs, eax
	mov gs, eax
	mov ss, eax
	; jmp FakeLabel:0x08
	jmp 0x08:FakeLabel
	FakeLabel:
		ret
