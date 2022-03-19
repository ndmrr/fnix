#include "pmm.h"
#include <klibc/io.h>
#include <stdint.h>
static pmmMemory pm;


void pmmInit(struct stivale2_struct* stivale_struct)
{
    LOG(LOG_INFO, "Initializing PMM");
    
    struct stivale2_struct_tag_memmap* map = bootloaderGetTag(stivale_struct, STIVALE2_STRUCT_TAG_MEMMAP_ID);
    
    for (uint32_t i = 0; i < map->entries; i++)
    {
        struct stivale2_mmap_entry entry = map->memmap[i];
        if (entry.type != STIVALE2_MMAP_USABLE) continue;
        pm.mem_size += entry.length;
        
        
    }
    
}

pmmMemory pmmGetMemory(void)
{
    return pm;
}