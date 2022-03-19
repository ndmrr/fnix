#include "gdt.h"



static gdt_register_t gdt_reg;
static gdt_descriptor_t gdt_descriptor[3];

gdt_descriptor_t gdtCreateNewDescriptor(uint32_t base, uint32_t limit, uint8_t access, uint8_t granularity)
{
    gdt_descriptor_t gdt;
    gdt.granularity = granularity;
    gdt.access = access;
    
    /* Granularity limit, and all of these flags are not needed in 64-bit mode as the CPU already demands for the limit and the base to be at the max addressable unit. */
    gdt.limit0 = limit;
    gdt.base2 = (base >> 24) & 0xff;
    gdt.base1 = (base >> 16) & 0xff;
    gdt.base0 = (base) & 0xffff;
    LOG(LOG_OK, "Added new GDT descriptor.");
    return gdt;
}

GlobalDescriptorTable gdtInstall(void)
{
    GlobalDescriptorTable gdt;
    LOG(LOG_INFO, "Installing GDT.");
    gdt.gdtr = &gdt_reg;
    gdt.gdtd = gdt_descriptor;
    
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    /* CPU Reserved. */
    gdt_descriptor[0] = gdtCreateNewDescriptor(0,0,0,0);;
    
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    /* Code segment */
    gdt_descriptor[1] = gdtCreateNewDescriptor(0,
                                               0XFFFFFF,
                                               GDT_KERNEL_CODE_SEGMENT,
                                               DESCRIPTOR_LONG_MODE | DESCRIPTOR_PAGE_GRANULARITY | DESCRIPTOR_LIMIT_MAX);
    
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    /* Data segment */
    gdt_descriptor[2] = gdtCreateNewDescriptor(0,
                                               0XFFFFFF,
                                               GDT_KERNEL_DATA_SEGMENT,
                                               DESCRIPTOR_LONG_MODE | DESCRIPTOR_PAGE_GRANULARITY | DESCRIPTOR_LIMIT_MAX);
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    /* Task State Segment */
    // gdt_descriptor[3]; // TODO: Task State Segment
    
    gdt_reg.offset = (uint64_t)gdt_descriptor;
    gdt_reg.limit = sizeof(gdt_descriptor) - 1;
    
    gdtFlush(&gdt_reg);
    
    
    LOG(LOG_OK, "Successfully installed.");
    
    return gdt;
    
}