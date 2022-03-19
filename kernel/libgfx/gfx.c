#include <libgfx/gfx.h>
#include <klibc/io.h>
static gfxGlobalRenderer gfx_gr = {0};

gfxGlobalRenderer gfxGetGlobalRenderer(void)
{
    return gfx_gr;
}
void gfxCreateGlobalRenderer(gfxGraphicsInfo gfx)
{
    gfx_gr.info = gfx;
    gfx_gr.vertex_color = 0xFFFFFFFF;
}
void gfxSwapbuffers(void)
{
    // TODO: 
    
    
    return;
    
}
void gfxSetVertexColor(uint8_t r, uint8_t g, uint8_t b)
{
    gfx_gr.vertex_color = r << 16 | g << 8 | b;
}
void gfxPlotPixel(uint32_t x, uint32_t y)
{
    *(gfx_gr.info.framebuffer_address + y * (gfx_gr.info.framebuffer_width) + x) = gfx_gr.vertex_color;
}
