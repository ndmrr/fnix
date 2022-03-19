bits 64

global loadIDT

loadIDT:

lidt [rdi]
sti
ret