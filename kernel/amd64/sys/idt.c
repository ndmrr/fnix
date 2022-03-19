#include "idt.h"
#include <klibc/io.h>
static idt_register_t idtr;
static idt_gate_t idtgates[256] = {0};
extern void loadIDT(idt_register_t* idt);


idt_gate_t idtNewGate(uint64_t offset, uint8_t gate_type)
{
    
    
    return (idt_gate_t)
    {
        .offset0 = (offset) & 0xffff,
        .offset1 = (offset >> 16) & 0xffff,
        .offset2 = (offset >> 32) & 0xffffffff,
        .sel = 0x8,
        .flags = gate_type,
        
        .ist = 0
    };
};
struct interrupt_frame
{
    uint16_t ip;
    uint16_t cs;
    uint16_t flags;
    uint16_t sp;
    uint16_t ss;
};
struct interrupt_frame;
__attribute__((interrupt)) 
void exceptionsError(struct interrupt_frame* frame)
{
    LOG(LOG_ERROR, "Unable to continue. An exception occured.");
    println("Roadblock ahead. An exception occured.");
    
    
    
    for (;;) asm("hlt");
}

InterruptDescriptorTable idtInstall(void)
{
    InterruptDescriptorTable idt;
    idt.reg = &idtr;
    idt.gates = idtgates;
    for (int i=0;i<31;i++)
        idtgates[i] = idtNewGate((uint64_t)exceptionsError, 0x8F);
    
    LOG(LOG_INFO, "Installing IDT.");
    idtr.limit = sizeof(idtgates)-1;
    idtr.base  = (uint64_t)idtgates;
    
    loadIDT(&idtr);
    
    LOG(LOG_OK, "Successfully installed.");
    
    return idt;
}