#include <stdint.h>
#include "stivale2.h"
#include <stddef.h>

static uint8_t stack[8192];



static struct stivale2_header_tag_framebuffer framebuffer =
{
	.tag = 
    {
        .identifier = STIVALE2_HEADER_TAG_FRAMEBUFFER_ID,
        .next = 0
    }
};


__attribute__((section(".stivale2hdr"), used))
static struct stivale2_header stivale2_header =
{
    .entry_point = 0,
    .stack =  (uintptr_t)stack + sizeof(stack),
    .flags = (1 << 1) | (1<<2) | (1<<3) | (1<<4),
    .tags = (uintptr_t)&framebuffer
};


void* bootloaderGetTag(struct stivale2_struct* stivale, uint64_t id)
{
    struct stivale2_tag *current_tag = (void*)stivale->tags;
    for (;;)
    {
        if (current_tag == NULL)
            return NULL;
        if ((current_tag->identifier) == id)
            return current_tag;
        current_tag = (void*)current_tag->next;
    }
}




