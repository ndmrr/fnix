

#ifndef PMM_H
#define PMM_H
#include <liblog/log.h>
#include <boot/stivale2.h>

typedef struct 
{
    uint32_t mem_size;
    struct stivale2_struct_tag_memmap*  mmap;
    uint8_t* bitmap;
    uint8_t  bitmap_size;
    uint32_t max_blocks;
}  pmmMemory ;

pmmMemory pmmGetMemory(void);;
void pmmInit(struct stivale2_struct* stivale_struct);

#endif 
