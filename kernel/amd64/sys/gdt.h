

#ifndef GDT_H
#define GDT_H
#include <liblog/log.h>
#include <stdint.h>


enum gdt_flags
{
    DESCRIPTOR_LONG_MODE   = 0b00100000,
    DESCRIPTOR_32_BIT_MODE = 0b01000000,
    DESCRIPTOR_16_BIT_MODE = 0b00000000,
    DESCRIPTOR_PAGE_GRANULARITY = 0b10000000,
    DESCRIPTOR_BLOCK_GRANULARITY = 0b00000000,
    DESCRIPTOR_LIMIT_MAX = 0b00001111,
    GDT_KERNEL_CODE_SEGMENT = 0x9A,
    GDT_KERNEL_DATA_SEGMENT = 0x92
};
typedef struct 
{
    uint16_t limit;
    uint64_t offset;
} __attribute__((packed)) gdt_register_t;


typedef struct 
{
    uint16_t limit0;
    uint16_t base0;
    uint8_t base1;
    uint8_t access;
    uint8_t granularity;
    uint8_t base2;
} __attribute__((packed)) gdt_descriptor_t;


typedef struct 
{
    uint16_t limit0;
    uint16_t base0;
    uint8_t base1;
    uint8_t access;
    uint8_t granularity;
    uint8_t base2;
    uint32_t base3;
    uint32_t resv;
} __attribute__((packed)) sys_segment_descriptor_t;

typedef struct
{
    
    gdt_register_t* gdtr;
    gdt_descriptor_t* gdtd;
    
} GlobalDescriptorTable;

GlobalDescriptorTable gdtInstall(void);
extern void gdtFlush(gdt_register_t * gdtr);
#endif 
