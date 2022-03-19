#include <boot/boot_stivale2.h>
#include <boot/stivale2.h>
#include <libgfx/gfx.h>
#include <meta/f8x16.h>
#include <liblog/log.h>
#include <klibc/io.h>
#include <amd64/sys/gdt.h>
#include <amd64/sys/idt.h>
#include <mem/pmm.h>
#include <amd64/sys/pic.h>
void KernelMain(struct stivale2_struct* stivale_struct)
{
    struct stivale2_struct_tag_framebuffer*fb;
    fb = bootloaderGetTag(stivale_struct, STIVALE2_STRUCT_TAG_FRAMEBUFFER_ID);
    gfxGraphicsInfo gi = (gfxGraphicsInfo)
    {
        .framebuffer_address = (uint32_t*)fb->framebuffer_addr,
        .framebuffer_width   = fb->framebuffer_width
    };
    gfxCreateGlobalRenderer(gi);
    
    for (int i=0;i<1024;i++)
    {
        for (int d = 0; d< 1024; d++)
        {
            
            gfxSetVertexColor(i/10,d/10,d / 3);
            gfxPlotPixel(i,d);
            
        }
    }
    gfxFont gfxfont = gfxCreateFont(font, 8,16);
    PushFontToActive(gfxfont);
    
    gdtInstall();
    idtInstall();
    picRemap();
    
    
    pmmInit(stivale_struct);
    for (int i=0;i<100;i++)
    {
        for (int d = 0; d< 100; d++)
        {
            
            gfxSetVertexColor(0,d*2,i*2);
            gfxPlotPixel(i + 512,d+512);
            
        }
    }
    
    printstr("NON-RESERVED RAM: ");
    char buffer[1024]; itoa(pmmGetMemory().mem_size, buffer, 10); printstr(buffer);
    printstr(" bytes");
    for (;;) asm ("hlt");
}