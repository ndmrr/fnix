

global gdtFlush

gdtFlush:
lgdt[rdi]
mov ax, 0x10
mov es, ax
mov ss, ax
mov ds, ax
mov fs, ax
mov gs, ax
push 0x08
lea rax, [rel .reload_cs]
push rax
retfq
.reload_cs:
ret 