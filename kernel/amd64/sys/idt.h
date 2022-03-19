

#ifndef IDT_H
#define IDT_H
#include <liblog/log.h>
#include <stdint.h>
typedef struct
{
    uint16_t limit;
    uint64_t base;
} __attribute__((packed)) idt_register_t;


typedef struct
{
    uint16_t offset0;
    uint16_t sel;
    uint8_t ist;
    uint8_t flags;
    uint16_t offset1;
    uint32_t offset2;
    uint32_t reserved;
} __attribute__((packed)) idt_gate_t;


typedef struct
{
    idt_register_t * reg;
    idt_gate_t * gates;
    
} InterruptDescriptorTable;
InterruptDescriptorTable idtInstall(void);


#endif 
